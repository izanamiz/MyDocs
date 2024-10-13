from django.db import models

# Create your models here.
class Cart(models.Model):
    user_id = models.IntegerField(null=False)
    class Meta:
            db_table = 'carts'

class CartItem(models.Model):
    cart = models.ForeignKey(Cart, on_delete=models.CASCADE)
    date_added = models.DateTimeField(auto_now_add=True)
    quantity = models.IntegerField(default = 1)
    product_id = models.IntegerField(unique=False, null=False)
    product_type = models.CharField(max_length=50)
    
    class Meta:
        db_table = 'cart_items'
        ordering = ['date_added']
    def augment_quantity(self, quantity):
        self.quantity = self.quantity + int(quantity)
        self.save()
