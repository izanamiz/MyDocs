#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string a;cin>>a;
	vector<int> s;
	for(int i=0; i<a.length(); i++){
		s.push_back(a[i]-'0');
	}
	int x;
	for(int i=0; i<s.size();i++)
		cout<<s[i];
}

