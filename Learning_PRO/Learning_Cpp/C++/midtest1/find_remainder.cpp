//Program for quotient and remainder of big number 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string a;cin>>a;
	int b;cin>>b;
	int mod=0;

	for(int i=0; i<a.length(); i++){
		mod = mod*10 +(a[i]-'0');
		mod = mod%b;
	}
	cout<<mod;
}

