from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework import permissions
from .models import *
from .serializers import *
import requests
# Create your views here.
class CategoryClothesRetrieveUpdateDestroy(APIView):
    def get_object(self, pk):
        return CategoryClothes.objects.get(pk=pk)
  
    def get(self, request, pk):
        categories = self.get_object(pk)
        serializer = CategoryClothesSerializer(categories)
        return Response(serializer.data)

    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            categories = self.get_object(pk)
            serializer = CategoryClothesSerializer(categories, data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
    def delete(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            categories = self.get_object(pk)
            categories.delete()
            return Response(status=status.HTTP_204_NO_CONTENT)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class CategoryClothesListView(APIView):
    def get(self, request):
        categories = CategoryClothes.objects.all()
        serializer = CategoryClothesSerializer(categories, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)   
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = CategoryClothesSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST) 
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class BranchRetrieveUpdateDestroy(APIView):
    def get_object(self, pk):
        return Branch.objects.get(pk=pk)
  
    def get(self, request, pk):
        branch = self.get_object(pk)
        serializer = BranchSerializer(branch)
        return Response(serializer.data)

    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            branch = self.get_object(pk)
            serializer = BranchSerializer(branch, data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
    def delete(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            branch = self.get_object(pk)
            branch.delete()
            return Response(status=status.HTTP_204_NO_CONTENT)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class BranchListView(APIView):
    def get(self, request):
        branchs = Branch.objects.all()
        serializer = BranchSerializer(branchs, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)   
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = BranchSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST) 
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class ClothesRetrieveUpdateDestroy(APIView):
    def get_object(self, pk):
        return Clothes.objects.get(pk=pk)
  
    def get(self, request, pk):
        clothes = self.get_object(pk)
        serializer = ClothesSerializer(clothes)
        return Response(serializer.data)

    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            clothes= self.get_object(pk)
            serializer = ClothesSerializer(clothes, data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
    def delete(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            clothes = self.get_object(pk)
            clothes.delete()
            return Response(status=status.HTTP_204_NO_CONTENT)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class ClothesListView(APIView):
    def get(self, request):
        clothes = Clothes.objects.all()
        serializer = ClothesSerializer(clothes, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)   
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = ClothesSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST) 
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class SearchClothesView(APIView):
    def get(self, request):
        keyword = request.query_params.get('keyword','')
        clothes = Clothes.objects.filter(name__icontains=keyword)
        serializer = ClothesSerializer(clothes, many= True)
        return Response(serializer.data, status=status.HTTP_200_OK) 