from django.urls import path
from . import views

urlpatterns = [
    path('shipment_status/', views.shipment_status),
    path('shipment_reg_update/', views.shipment_reg_update),
]