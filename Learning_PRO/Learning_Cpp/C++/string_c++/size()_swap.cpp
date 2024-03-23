#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<s1.length()<<" "<<s2.size()<<endl;
	if(s1==s2) cout<<1;
	else cout<<0;
	cout<<endl<<s1[0]<<endl;
	swap(s1,s2);
	cout<<s1<<" "<<s2;
}
