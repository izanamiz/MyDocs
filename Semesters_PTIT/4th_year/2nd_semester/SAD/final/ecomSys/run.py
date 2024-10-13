import subprocess
import os

services = [
    'user_service',
    'manager_service',
    'book_service',
    'clothes_service',
    'mobile_service',
    'cart_service',
    'search_service',
    'order_service'
]
ports = [
    8000,  
    8001, 
    8002, 
    8003, 
    8004, 
    8005, 
    8006,  
    8007
]

# Run each project
for service, port in zip(services, ports):
    command = f"py D:/Documents/MyDocs/Semesters_PTIT/4th_year/2nd_semester/SAD/final/ecomSys/{service}/manage.py runserver {port}"
    subprocess.Popen(command, shell=True)         
print("All Django projects have been started.")
