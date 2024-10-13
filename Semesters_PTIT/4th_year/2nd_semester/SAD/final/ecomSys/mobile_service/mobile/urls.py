from django.urls import path
from .views import *
urlpatterns = [
    path('mobiles/', MobileListView.as_view()),
    path('mobiles/<int:pk>/', MobileRetrieveUpdateDestroy.as_view()),
    path('branchs/', BranchMobileListView.as_view()),
    path('branchs/<int:pk>/', BranchMobileRetrieveUpdateDestroy.as_view()),
    path('search/', SearchMobileView.as_view(), name='search_book')

]
