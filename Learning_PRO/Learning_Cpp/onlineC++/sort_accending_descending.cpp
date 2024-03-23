#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> a(5);
	for(int i=0; i<a.size();i++)
		cin>>a[i];
	sort(a.rbegin(),a.rend());
	for(auto x: a)
		cout<<x<<" ";
	
}

