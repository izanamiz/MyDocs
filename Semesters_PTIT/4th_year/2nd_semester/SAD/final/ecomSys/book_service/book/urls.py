from django.urls import path
from .views import *
urlpatterns = [
    path('books/', ListBookView.as_view(), name="books"),
    path('books/<int:pk>/', BookRetrieveUpdateDestroy.as_view(), name="book_id"),
    path('books/update/<int:pk>/', UpdateBook.as_view()),
    path('categories/', ListCategoryView.as_view()),
    path('authors/', AuthorListView.as_view()),
    path('publishers/', PublisherListView.as_view()),
    path('search/', SearchBookView.as_view(), name='search_book')
]