from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework import permissions
from .models import *
from .serializers import *
import requests
# Create your views here.
class BranchMobileRetrieveUpdateDestroy(APIView):
    def get_object(self, pk):
        return BranchMobile.objects.get(pk=pk)
  
    def get(self, request, pk):
        branch = self.get_object(pk)
        serializer = BranchMobileSerializer(branch)
        return Response(serializer.data)

    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            branch = self.get_object(pk)
            serializer = BranchMobileSerializer(branch, data=request.data)
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
    
class BranchMobileListView(APIView):
    def get(self, request):
        branchs = BranchMobile.objects.all()
        serializer = BranchMobileSerializer(branchs, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)   
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = BranchMobileSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST) 
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)

class MobileRetrieveUpdateDestroy(APIView):
    def get_object(self, pk):
        return Mobile.objects.get(pk=pk)
  
    def get(self, request, pk):
        mobile = self.get_object(pk)
        serializer = MobileSerializer(mobile)
        return Response(serializer.data)

    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            mobile = self.get_object(pk)
            serializer = MobileSerializer(mobile, data=request.data)
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
            mobile = self.get_object(pk)
            mobile.delete()
            return Response(status=status.HTTP_204_NO_CONTENT)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
    
class MobileListView(APIView):
    def get(self, request):
        mobiles = Mobile.objects.all()
        serializer = MobileSerializer(mobiles, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)   
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = MobileSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST) 
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)

class SearchMobileView(APIView):
    def get(self, request):
        keyword = request.query_params.get('keyword','')
        mobiles = Mobile.objects.filter(name__icontains=keyword)
        serializer = MobileSerializer(mobiles, many= True)
        return Response(serializer.data, status=status.HTTP_200_OK) 