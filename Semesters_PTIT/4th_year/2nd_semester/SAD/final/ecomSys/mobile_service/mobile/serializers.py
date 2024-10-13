from rest_framework import serializers
from .models import *

class BranchMobileSerializer(serializers.ModelSerializer):
    class Meta:
        model = BranchMobile
        fields = "__all__"

class MobileSerializer(serializers.ModelSerializer):
    class Meta:
        model = Mobile
        fields = "__all__"
