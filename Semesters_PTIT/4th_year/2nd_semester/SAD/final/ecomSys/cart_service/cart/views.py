from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from .models import *
from .serializers import *
import requests

# Create your views here.
class ShowCartItemView(APIView):
    def get(self, request):
        token_verification_url = "http://127.0.0.1:8000/api/user/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code != 200:
            return Response({"message":"Bạn phải đăng nhập"})
        user = response.json().get("user")
        user_id = user.get("id")
        cart = Cart.objects.filter(user_id= user_id).first()
        cart_item_list = CartItem.objects.filter(cart=cart.id)
        serializer = CartItemSerializer(cart_item_list, many = True)
        totalPrice = 0
        for cart_item in cart_item_list:
            if cart_item.product_type == 'book':
                cart_item_id = cart_item.product_id
                response = requests.get(f'http://127.0.0.1:8002/api/books/{cart_item_id}/')
                book = response.json()
                totalPrice += cart_item.quantity * book['price']
            if cart_item.product_type == 'clothes':
                cart_item_id = cart_item.product_id
                response = requests.get(f'http://127.0.0.1:8003/api/clothes/{cart_item_id}/')
                clothes = response.json()
                totalPrice += cart_item.quantity * clothes['price']
            if cart_item.product_type == 'mobile':
                cart_item_id = cart_item.product_id
                response = requests.get(f'http://127.0.0.1:8004/api/mobiles/{cart_item_id}/')
                mobile = response.json()
                totalPrice += cart_item.quantity * mobile['price']
        response = {
            'data': serializer.data,
            'totalPrice': totalPrice,
            'message':'Get successfully'
        }
        return Response(response, status=status.HTTP_200_OK)
class AddToCart(APIView):
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8000/api/user/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            user = response.json().get("user")
            user_id = user.get("id")
            quantity = request.data.get('quantity')
            product_id = request.data.get('product_id')
            product_type = request.data.get('product_type')
            if product_type == 'book':
                response = requests.get(f'http://127.0.0.1:8002/api/books/{product_id}/')
                if response.status_code !=200:
                    return Response({"message":"Sản phẩm không tồn tại"}, status=status.HTTP_400_BAD_REQUEST)
            if product_type == 'clothes':
                response = requests.get(f'http://127.0.0.1:8003/api/clothes/{product_id}/')
                if response.status_code !=200:
                    return Response({"message":"Sản phẩm không tồn tại"}, status=status.HTTP_400_BAD_REQUEST)
            if product_type == 'mobile':
                response = requests.get(f'http://127.0.0.1:8004/api/mobiles/{product_id}/')
                if response.status_code !=200:
                    return Response({"message":"Sản phẩm không tồn tại"}, status=status.HTTP_400_BAD_REQUEST)
            if user_id is None:
                return Response({'message':'Bạn phải đăng nhập'}, status=status.HTTP_403_FORBIDDEN)
            else:
                cart = Cart.objects.filter(user_id=user_id).first()
                if cart is not None:
                    cart_items = CartItem.objects.filter(cart=cart.id)
                    check_product_in_cart = False
                    for cart_item in cart_items:
                        if cart_item.product_id == int(product_id) and cart_item.product_type == product_type:
                            cart_item.augment_quantity(quantity)
                            check_product_in_cart = True
                            break
                    if not check_product_in_cart:
                        cart_item1 = {'cart':cart.id, 'quantity':quantity,'product_id':product_id, 'product_type': product_type}
                        cart_item = CartItemSerializer(data=cart_item1)
                        if cart_item.is_valid():
                            cart_item.save()
                    return Response({'message':"Thêm sản phẩm vào giỏ hàng thành công"}, status=status.HTTP_201_CREATED)
                else:
                    cart_new = Cart(user_id=user_id)
                    cart_new.save()
                    cart = Cart.objects.get(user_id=user_id)
                    cart_items = CartItem.objects.filter(cart=cart.id)
                    check_product_in_cart = False
                    for cart_item in cart_items:
                        if cart_item.product_id == int(product_id) and cart_item.product_type == product_type:
                            cart_item.augment_quantity(quantity)
                            check_product_in_cart = True
                            break
                    if not check_product_in_cart:
                        cart_item1 = {'cart':cart.id, 'quantity':quantity,'product_id':product_id, 'product_type': product_type}
                        cart_item = CartItemSerializer(data=cart_item1)
                        if cart_item.is_valid():
                            cart_item.save()
                        else:
                            return Response(cart_item.errors, status=status.HTTP_400_BAD_REQUEST)
                    return Response({'message':"Thêm sản phẩm vào giỏ hàng thành công"}, status=status.HTTP_201_CREATED)
class DeleteCart(APIView):
    def delete(self, request, pk):
        token_verification_url = "http://127.0.0.1:8000/api/user/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code !=200:
            return Response({"message":"Bạn phải đăng nhập"})
        user = response.json().get("user")
        user_id = user.get("id")
        cart = Cart.objects.filter(user_id= user_id).first()
        if cart is None:
            return Response({"message":"Cart không tồn tại"}, status=status.HTTP_404_NOT_FOUND)
        cart.delete()
        return Response({'message':'Xóa thành công'}, status=status.HTTP_200_OK)
class UpdateCart(APIView):
    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8000/api/user/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code !=200:
            return Response({"message":"Bạn phải đăng nhập"})
        user = response.json().get("user")
        user_id = user.get("id")
        cart = Cart.objects.filter(user_id= user_id).first()
        quantity = int(request.data.get('quantity'))
        cart_item = CartItem.objects.filter(cart=cart.id, pk=pk).first()
        if cart_item is None:
            return Response({"message":"Sản phẩm không tồn tại"}, status=status.HTTP_404_NOT_FOUND)
        cart_item.quantity = quantity
        if quantity == 0:
            cart_item.delete()
            return Response({'message':'Cập nhập thành công'}, status= status.HTTP_200_OK)
        else:
            cart_item.save()           
            return Response({'message':'Cập nhập thành công'}, status=status.HTTP_200_OK)
 
    def delete(self, request, pk):
        token_verification_url = "http://127.0.0.1:8000/api/user/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code !=200:
            return Response({"message":"Bạn phải đăng nhập"})
        user = response.json().get("user")
        user_id = user.get("id")
        cart = Cart.objects.filter(user_id= user_id).first()
        cart_item = CartItem.objects.filter(cart=cart.id, pk=pk).first()
        if cart_item is None:
            return Response({"message":"Sản phẩm không tồn tại"}, status=status.HTTP_404_NOT_FOUND)
        cart_item.delete()
        return Response({'message':'Xóa thành công'}, status=status.HTTP_200_OK)
    
