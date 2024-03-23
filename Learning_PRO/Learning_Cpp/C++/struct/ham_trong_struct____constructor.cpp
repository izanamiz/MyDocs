/*
	Ham khoi tao cau truc du lieu(constructor)
	ten_cau_truc_du_lieu(cac tham so)
	{
		noi dung;
	}	
*/
#include <iostream>

using namespace std;

struct person
{
    string name, phoneNumber, address;

    person(string _name, string _phoneNumber, string _address)
    {
        name = _name;
        phoneNumber = _phoneNumber;
        address = _address;
    }

    void printData()
    {
        cout << name << '\n' << phoneNumber << '\n' << address << '\n';
    }
};

int main()
{
    person admin = person("Admin Tong Quan", "113", "The Internet");

    // In ra giá tri cua bien thanh phan
    admin.printData();
    return 0;
}	
