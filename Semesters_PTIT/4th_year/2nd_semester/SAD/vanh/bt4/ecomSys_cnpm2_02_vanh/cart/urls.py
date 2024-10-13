from django.urls import path
from .views import CartItemCreate, CartItemList, CartItemRetrieve

urlpatterns = [
    path("", CartItemCreate.as_view(), name="cart-item-create"),
    path("<int:pk>/", CartItemRetrieve.as_view(), name="cart-item-retrieve"),
    path("all/", CartItemList.as_view(), name="cart-item-list"),
]
