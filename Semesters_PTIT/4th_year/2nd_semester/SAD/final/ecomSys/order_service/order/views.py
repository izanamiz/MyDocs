from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from .models import *
from .serializers import *
import requests
from django.utils import timezone
import json
# Create your views here.
class CreateOrderView(APIView):
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8000/api/user/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code != 200:
            return Response({"message":"Bạn phải đăng nhập"})
        user = response.json().get("user")
        user_id = user.get("id")
        cart_url = 'http://127.0.0.1:8005/api/get-items/'
        response = requests.get(cart_url, headers=headers)
        cart = response.json()
        cart_items = cart.get("data")
        cart_id = cart.get("id")
        address=  request.data.get("shipping_address")
        order = Order(user_id=user_id,orderDate=timezone.now(),totalPrice=cart.get("totalPrice"),shipping_address=address,phone=user.get("phone_number"),status="PENDING") 
        order.save()
        for cart_item in cart_items:
            cart_item_id = cart_item.get("id")
            product_id = cart_item.get("product_id")
            product_type = cart_item.get("product_type")
            price = 0
            if product_type == 'book':
                response = requests.get(f'http://127.0.0.1:8002/api/books/{product_id}/')
                print(response.json())
                if response.status_code ==200:
                    price +=  int(response.json().get("price"))
            if product_type == 'clothes':
                response = requests.get(f'http://127.0.0.1:8003/api/clothes/{product_id}/')
                if response.status_code ==200:
                    price +=  int(response.json().get("price"))
            if product_type == 'mobile':
                response = requests.get(f'http://127.0.0.1:8004/api/mobiles/{product_id}/')
                if response.status_code ==200:
                    price += int(response.json().get("price"))
            order_detail =  OrderDetail(order=order,product_id=cart_item.get("product_id"),product_type=product_type, price=price,quantity=cart_item.get("quantity"))
            order_detail.save()
            requests.delete(f'http://127.0.0.1:8005/api/update-cart/{cart_item_id}/', headers= headers)
        requests.delete(f'http://127.0.0.1:8005/api/delete-cart/{cart_id}/', headers=headers)
        order_1 = {'id':order.id, 'user_id':order.user_id,'orderDate':order.orderDate, 'totalPrice': order.totalPrice,'shipping_address':order.shipping_address,'phone':order.phone, 'status':order.status}
        print(order)
        serializer = OrderSerializer(data=order_1)
        if(serializer.is_valid()):
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors, status=status.HTTP_201_CREATED)



