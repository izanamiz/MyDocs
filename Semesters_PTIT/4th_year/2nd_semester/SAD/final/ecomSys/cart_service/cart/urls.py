from django.urls import path
from .views import *
urlpatterns = [
    path('get-items/', ShowCartItemView.as_view(), name='getcarts'),
    path('add-to-cart/', AddToCart.as_view(), name="carts"),
    path('update-cart/<int:pk>/', UpdateCart.as_view(), name="carts-update"),
    path('delete-cart/<int:pk>/', DeleteCart.as_view())
]