# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from django.http import HttpResponse
from django.shortcuts import render
import json
from django.views.decorators.csrf import csrf_exempt
from user_model.models import user_registration

# This function inserts the data into the user_registration table.
def data_insert(fname, lname, email, mobile, password, address):
    user_data = user_registration(
        fname=fname,
        lname=lname,
        email=email,
        mobile=mobile,
        password=password,
        address=address
    )
    user_data.save()
    return 1

# This function gets the data from the front end.
@csrf_exempt
def registration_req(request):
    # The following are the input fields.
    fname = request.POST.get("First Name")
    lname = request.POST.get("Last Name")
    email = request.POST.get("Email Id")
    mobile = request.POST.get("Mobile Number")
    password = request.POST.get("Password")
    cnf_password = request.POST.get("Confirm Password")
    address = request.POST.get("Address")
    resp = {}

    # Checking that all fields are available.
    if fname and lname and email and mobile and password and cnf_password and address:
        # Checking that the mobile number is only 10 digits.
        if len(str(mobile)) == 10:
            # Checking that Password and Confirm Password both are the same.
            if password == cnf_password:
                # After all validation, it will call the data_insert function.
                respdata = data_insert(fname, lname, email, mobile, password, address)
                # If it returns value then will show success.
                if respdata:
                    resp['status'] = 'Success'
                    resp['status_code'] = '200'
                    resp['message'] = 'User is registered Successfully.'
                # If it is not returning any value then the show will fail.
                else:
                    resp['status'] = 'Failed'
                    resp['status_code'] = '400'
                    resp['message'] = 'Unable to register user, Please try again.'
            # If the Password and Confirm Password is not matched then it will be through error.
            else:
                resp['status'] = 'Failed'
                resp['status_code'] = '400'
                resp['message'] = 'Password and Confirm Password should be same.'
        # If the mobile number is not in 10 digits then it will be through error.
        else:
            resp['status'] = 'Failed'
            resp['status_code'] = '400'
            resp['message'] = 'Mobile Number should be 10 digit.'
    # If any mandatory field is missing then it will be through a failed message.
    else:
        resp['status'] = 'Failed'
        resp['status_code'] = '400'
        resp['message'] = 'All fields are mandatory.'

    return HttpResponse(json.dumps(resp), content_type='application/json')
