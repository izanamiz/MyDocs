from django.urls import path
from .views import *
urlpatterns = [
    path('search/', SearchProduct.as_view())
]
