#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<a.size();i++)
		cin>>a[i];
	//a.insert(a.begin()+1,1);
	//cout<<&(*a.begin());
	vector<int>b(5,5);
	a.insert(a.begin()+1,5,6);
	a.erase(a.begin()+1);
	for(auto x : a)
		cout<<x<<" ";
}
