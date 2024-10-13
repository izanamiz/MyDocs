from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
import requests
# Create your views here.
class SearchProduct(APIView):
    def post(self, request):
        keyword = request.data.get('keyword','')
        if keyword != '':
            response={}
            book_response = requests.get(f'http://127.0.0.1:8002/api/search/?keyword={keyword}')
            if book_response.status_code ==200:
                books = book_response.json()
                response['books'] = books
            clothes_response = requests.get(f'http://127.0.0.1:8003/api/search/?keyword={keyword}')
            if clothes_response.status_code ==200:
                clothes = clothes_response.json()
                response['clothes'] = clothes
            mobile_response = requests.get(f'http://127.0.0.1:8004/api/search/?keyword={keyword}')
            if mobile_response.status_code ==200:
                mobiles = mobile_response.json()
                response['mobiles'] = mobiles        
            return Response(response, status=status.HTTP_200_OK)
        else:
            return Response(status=status.HTTP_200_OK)    

