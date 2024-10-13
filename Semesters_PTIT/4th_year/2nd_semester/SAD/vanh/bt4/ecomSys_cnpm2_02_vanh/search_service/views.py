from rest_framework import generics
from rest_framework.response import Response
from book.models import Book
from .serializers import BookSearchSerializer

# http://127.0.0.1:8000/api/search/?query=conan

class BookSearch(generics.ListAPIView):
    serializer_class = BookSearchSerializer

    def get_queryset(self):
        query = self.request.query_params.get('query', None)
        if query:
            queryset = Book.objects.filter(title__icontains=query) | Book.objects.filter(author__icontains=query)
            return queryset
        else:
            return Book.objects.none()

    def list(self, request, *args, **kwargs):
        queryset = self.get_queryset()
        serializer = self.get_serializer(queryset, many=True)
        return Response(serializer.data)
