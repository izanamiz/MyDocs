from django.urls import path
from .views import BookSearch

urlpatterns = [
    path('', BookSearch.as_view(), name='book-search'),
]
