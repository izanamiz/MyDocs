from rest_framework import status
from rest_framework.response import Response
from rest_framework.views import APIView

from .authentication import SafeJWTAuthentication
from .utils import generate_access_token, generate_refresh_token
from .serializers import ChangePasswordSerializer, UpdateProfileSerializer, UserInfoSerializer, UserLoginSerializer, UserSerializer
from rest_framework.permissions import IsAuthenticated
from rest_framework.permissions import AllowAny

class RegisterView(APIView):
    permission_classes = [AllowAny]
    def post(self, request):
        serializer = UserSerializer(data=request.data)

        if serializer.is_valid():
            user = serializer.save()
            access_token = generate_access_token(user)
            refresh_token = generate_refresh_token(user)

            user_serializer = UserInfoSerializer(user)

            return Response({
                'user': user_serializer.data,
                'refresh': refresh_token,
                'access': access_token,
            }, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class LoginView(APIView):
    permission_classes = [AllowAny]
    def post(self, request):
        serializer = UserLoginSerializer(data=request.data)
        if serializer.is_valid():
            user = serializer.validated_data  
            access_token = generate_access_token(user)
            refresh_token = generate_refresh_token(user)

            user_serializer = UserInfoSerializer(user)
            
            return Response({
                'user': user_serializer.data,
                'refresh': refresh_token,
                'access': access_token,
            }, status=status.HTTP_200_OK)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class UserInfoView(APIView):
    permission_classes = [IsAuthenticated]
    authentication_classes = [SafeJWTAuthentication]

    def get(self, request):
        user = request.user
        serializer = UserInfoSerializer(user)
        return Response({"user":serializer.data, "message":"Token is valid"}, status=status.HTTP_200_OK)
