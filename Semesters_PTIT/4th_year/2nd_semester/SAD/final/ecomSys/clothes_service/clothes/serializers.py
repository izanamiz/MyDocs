from rest_framework import serializers
from .models import *

class BranchSerializer(serializers.ModelSerializer):
    class Meta:
        model = Branch
        fields = "__all__"

class ClothesSerializer(serializers.ModelSerializer):
    class Meta:
        model = Clothes
        fields = "__all__"
class CategoryClothesSerializer(serializers.ModelSerializer):
    class Meta:
        model = CategoryClothes
        fields = "__all__"