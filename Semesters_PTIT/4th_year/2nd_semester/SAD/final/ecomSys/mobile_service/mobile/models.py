from django.db import models

class BranchMobile(models.Model):
    name = models.CharField(max_length=255)
    address = models.CharField(max_length=255)
    email = models.CharField(max_length=255)
    phone = models.CharField(max_length=10)
    class Meta:
        db_table = 'branchs_mobile'
class Mobile(models.Model):
    name = models.CharField(max_length=255)
    description = models.TextField(null=True)
    price = models.IntegerField()
    quantity = models.IntegerField()
    branch = models.ForeignKey(BranchMobile, on_delete=models.CASCADE)
    class Meta:
        db_table = 'mobiles'