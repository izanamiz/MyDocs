from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework import permissions
from .models import *
import requests
from .serializers import CategorySerializer, AuthorSerializer, BookSerializer, PublisherSerializer
# Create your views here.

class ListCategoryView(APIView):
    def get(self, request):
        categories = CategoryBook.objects.all()
        serializer = CategorySerializer(categories, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)
    
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = CategorySerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)

class ListBookView(APIView):
    def get(self, request):
        books = Book.objects.all()
        serializer = BookSerializer(books, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)
    
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = BookSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class UpdateBook(APIView):
    def get_object(self, pk):
        return Book.objects.get(pk=pk)
    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            book = self.get_object(pk)
            serializer = BookSerializer(book, data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)

class BookRetrieveUpdateDestroy(APIView):
    def get_object(self, pk):
        return Book.objects.get(pk=pk)

    def get(self, request, pk):
        book = self.get_object(pk)
        serializer = BookSerializer(book)
        return Response(serializer.data)
    
    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            book = self.get_object(pk)
            serializer = BookSerializer(book, data=request.data)
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
            book = self.get_object(pk)
            book.delete()
            return Response(status=status.HTTP_204_NO_CONTENT)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class PublisherRetrieveUpdateDestroy(APIView):
    def get_object(self, pk):
        return Publisher.objects.get(pk=pk)
  
    def get(self, request, pk):
        publisher = self.get_object(pk)
        serializer = PublisherSerializer(publisher)
        return Response(serializer.data)

    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            publisher = self.get_object(pk)
            serializer = PublisherSerializer(publisher, data=request.data)
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
            publisher = self.get_object(pk)
            publisher.delete()
            return Response(status=status.HTTP_204_NO_CONTENT)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class PublisherListView(APIView):
    def get(self, request):
        publishers = Publisher.objects.all()
        serializer = PublisherSerializer(publishers, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)   
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = PublisherSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST) 
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)

class AuthorRetrieveUpdateDestroy(APIView):
    def get_object(self, pk):
        return Author.objects.get(pk=pk)
  
    def get(self, request, pk):
        author = self.get_object(pk)
        serializer = AuthorSerializer(author)
        return Response(serializer.data)

    def put(self, request, pk):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            author = self.get_object(pk)
            serializer = AuthorSerializer(author, data=request.data)
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
            author = self.get_object(pk)
            author.delete()
            return Response(status=status.HTTP_204_NO_CONTENT)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
class AuthorListView(APIView):
    def get(self, request):
        authors = Author.objects.all()
        serializer = AuthorSerializer(authors, many = True)
        return Response(serializer.data, status=status.HTTP_200_OK)   
    def post(self, request):
        token_verification_url = "http://127.0.0.1:8001/api/manager/info/"
        headers = {'Authorization': request.headers.get('Authorization')}
        response = requests.get(token_verification_url, headers=headers)
        if response.status_code == 200:
            serializer = AuthorSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({"message":"Bạn không có quyền"}, status=status.HTTP_403_FORBIDDEN)
        
class SearchBookView(APIView):
    def get(self, request):
        keyword = request.query_params.get('keyword','')
        books = Book.objects.filter(title__icontains=keyword)
        serializer = BookSerializer(books, many= True)
        return Response(serializer.data, status=status.HTTP_200_OK) 