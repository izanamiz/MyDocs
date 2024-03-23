#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
//	string a="PTIT";
//	string b="PTIT";
//	string c=a+b;
//	cout<< (a<= b) << endl;

//	int tuoi; 
//	string ten;
//	cin>>tuoi;
//	cin.ignore();
//	getline(cin,ten);
//	cout<<ten<<" "<<tuoi;
	int n;cin>>n;
	cin.ignore(); // xoa dau '\n'
	// chi dat sau khi nhap so
	string ten;
	for(int i=0; i<n; i++){
		getline(cin,ten);
		cout<<ten<<endl;

	}
}
