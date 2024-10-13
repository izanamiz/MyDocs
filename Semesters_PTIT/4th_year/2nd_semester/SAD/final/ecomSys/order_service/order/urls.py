from django.urls import path
from .views import *
urlpatterns = [
    path('create-order/', CreateOrderView.as_view(), name='create'),

]