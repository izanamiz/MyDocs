from django.db import models

class Branch(models.Model):
    name = models.CharField(max_length=255)
    address = models.CharField(max_length=255)
    email = models.CharField(max_length=255)
    class Meta:
        db_table = 'branchs'
class CategoryClothes(models.Model):
    name = models.CharField(max_length=255)
    des = models.TextField()
    class Meta:
        db_table = 'categories'
# Create your models here.
class Clothes(models.Model):
    name = models.CharField(max_length=255)
    price = models.IntegerField()
    size = models.CharField(max_length=10)
    description = models.TextField(null=True)
    branch = models.ForeignKey(Branch, on_delete=models.CASCADE)
    category = models.ForeignKey(CategoryClothes, on_delete=models.CASCADE)
    class Meta:
        db_table = 'clothes'