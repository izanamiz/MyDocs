from rest_framework import serializers
from .models import CategoryBook, Book, Author, Publisher

class CategorySerializer(serializers.ModelSerializer):
    class Meta:
        model = CategoryBook
        fields = "__all__"
class AuthorSerializer(serializers.ModelSerializer):
    class Meta:
        model = Author
        fields = "__all__"

class BookSerializer(serializers.ModelSerializer):
    class Meta:
        model = Book
        fields = "__all__"
class PublisherSerializer(serializers.ModelSerializer):
    class Meta:
        model = Publisher
        fields = "__all__"