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
	sinhVien sv; //sv[1000]; sv[0].age;
//	cin>>sv.age; //<ten_bien_struct>.<ten_bien_thanh_phan>
//	cout<<sv.age;
	sv = {"Vanh", "B20DCCN075", 19}; //gan dung thu tu
//	sv.name="Vanh";
//	sv.ID="B20DCCN075";
//	sv.age = 19;
	cout<< sv.name <<endl <<sv.ID <<endl <<sv.age;
}
