from django.urls import path
from .views import BookListCreate, BookRetrieve, BookList

urlpatterns = [
    path('', BookListCreate.as_view(), name='book-list-create'),
    path('<int:pk>/', BookRetrieve.as_view(), name='book-retrieve'),
    path('all/', BookRetrieve.as_view(), name='book-list'),
]
