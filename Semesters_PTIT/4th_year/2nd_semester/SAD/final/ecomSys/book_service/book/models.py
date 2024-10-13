from django.db import models

# Create your models here.
class CategoryBook(models.Model):
    name = models.CharField(max_length=100, unique=True)
    des = models.TextField(null=True)
    class Meta:
            db_table = "categories_books"
    def __str__(self):
        return self.name

class Author(models.Model):
    name = models.CharField(max_length=100)
    phone = models.CharField(max_length=10)
    address = models.CharField(max_length=255)
    mail = models.CharField(max_length=255)
    class Meta:
        db_table = "authors"
class Publisher(models.Model):
    name = models.CharField(max_length=100)
    phone = models.CharField(max_length=10)
    address = models.CharField(max_length=255)
    mail = models.CharField(max_length=255)
    class Meta:
        db_table = "publisher"
class Book(models.Model):
    title = models.CharField(max_length=100, unique=True)
    author = models.ForeignKey(Author, on_delete=models.CASCADE)
    price = models.FloatField()
    quantity = models.IntegerField()
    des = models.TextField(null=True)
    category = models.ForeignKey(CategoryBook, on_delete=models.CASCADE)
    publisher = models.ForeignKey(Publisher, on_delete=models.CASCADE)
    class Meta:
        db_table = "books"
    def __str__(self):
        return self.title