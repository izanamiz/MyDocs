from django.db import models

class Order(models.Model):
    user_id = models.IntegerField()
    orderDate = models.DateTimeField()
    totalPrice = models.FloatField()
    shipping_address = models.CharField(max_length=255)
    phone = models.CharField(max_length=10)
    status = models.CharField(max_length=50)
    class Meta:
        db_table = "orders"
# Create your models here.
class OrderDetail(models.Model):
    order = models.ForeignKey(Order, on_delete=models.CASCADE)
    product_id = models.IntegerField()
    product_type = models.CharField(max_length=50)
    price = models.FloatField()
    quantity = models.IntegerField()
    class Meta:
        db_table = "order_details"
