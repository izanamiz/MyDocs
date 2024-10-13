from django.contrib import admin
from django.urls import path, include

urlpatterns = [
    path("admin/", admin.site.urls),
    path("api/book/", include("book.urls")),
    path("api/cart/", include("cart.urls")),
    path("api/search/", include("search_service.urls")),
]