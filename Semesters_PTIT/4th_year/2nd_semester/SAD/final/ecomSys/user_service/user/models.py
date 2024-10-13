from django.contrib.auth.models import AbstractUser
from django.db import models

class User(AbstractUser):
    fname = models.CharField(max_length=50)
    lname = models.CharField(max_length=50)
    email = models.CharField(max_length=50)
    password = models.CharField(max_length=50)
    address = models.CharField(max_length=200)
    phone_number = models.CharField(max_length=20)
    username = models.CharField(max_length=100, unique=False, null=True, default=None)
    USERNAME_FIELD = 'email' 
    REQUIRED_FIELDS = ['username'] 

    def __str__(self):
        return self.email
