#include<iostream>
#include<string>
using namespace std;
int main(){
	int age;string name;
	cout<<"Nhap tuoi: ";
	cin>>age;
// xoa bo nho dem	
//	fflush(stdin);
	std::cin.ignore(32767,'\n');
	//cin.ignore();
	//cin.ignore() chi de sau khi nhap so
	cout<<"Nhap ten: ";
	getline(cin,name,'?');	//getline(cin,name,'\n');
	//getline(cin,name,'?') : nhap du lieu toi khi gap dau '?'
	cout<<"Xin chao: "<<name;
	
	cout<<endl<<name.length();
	cout<<endl<<name.size();
}
