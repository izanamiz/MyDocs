from django.urls import path
from .views import *
urlpatterns = [
    path('register/', AddManagerView.as_view(), name='register'),
    path('login/', LoginView.as_view(), name='login'),
    path('info/', ManagerInfoView.as_view(), name='manager-detail'),
]
