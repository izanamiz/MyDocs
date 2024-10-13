from rest_framework import serializers
from .models import CartItem
from book.models import Book
from book.serializers import BookSerializer


class CartItemSerializer(serializers.ModelSerializer):
    book_id = serializers.IntegerField(write_only=True)
    book = serializers.IntegerField(
        source="book.id", read_only=True
    )  # Trường book để đọc thông tin của sách

    class Meta:
        model = CartItem
        fields = [
            "id",
            "book_id",
            "book",
            "quantity",
        ]

    def validate_book_id(self, value):
        try:
            Book.objects.get(pk=value)
        except Book.DoesNotExist:
            raise serializers.ValidationError("Book with this title does not exist.")
        return value

    def create(self, validated_data):
        book_id = validated_data.pop("book_id")
        book = Book.objects.get(pk=book_id)
        cart_item = CartItem.objects.create(book=book, **validated_data)
        return cart_item
