#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char k;
	string s;
	cin>>n;
	cin.ignore();
	cin>>k; cin.ignore();
	getline(cin,s);
	strupr(s);
	toupper(k);
	int count=0;	
	for(int i=0; i<s.length();i++)
	{
			if(s[i]==k) count++;
	}
	cout<<count;
	
}
