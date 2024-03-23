#include<iostream>
using namespace std;
int main(){
	string mystring="HELLO";
	cout<<mystring[0]<<endl;
	mystring[0]='J';
	cout<<mystring<<endl;
	cout<<mystring.size();//mystring.length
}
