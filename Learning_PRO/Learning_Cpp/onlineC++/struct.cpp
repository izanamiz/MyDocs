#include<iostream>
using namespace std;
struct sinhVien
{
	string name;
	string ID;
	int age; 
};
int main()
{
	sinhVien sv;
	sv.age = 19;
	cout<<sv.age;
}
