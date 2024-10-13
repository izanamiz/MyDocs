from django.urls import path
from .views import *
urlpatterns = [
    path('clothes/', ClothesListView.as_view(), name="clothes"),
    path('clothes/<int:pk>/', ClothesRetrieveUpdateDestroy.as_view()),
    path('branchs/', BranchListView.as_view()),
    path('categories/', CategoryClothesListView.as_view()),
    path('search/', SearchClothesView.as_view(), name='search_book')

]
