from rest_framework import serializers
from book.models import Book

class BookSearchSerializer(serializers.ModelSerializer):
    class Meta:
        model = Book
        fields = ['id', 'title', 'author']
