#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string s= "ProPTIT nam nay la sinh nhat 10 tuoi";
	int pos = s.find("nam");
	s.insert(pos,"2021 ");
	cout<<s<<endl;
	s.erase(pos,4);
	cout<<s<<endl;
	
	s.replace(pos,8,"nam 2021");
	cout<<s<<endl;

	
}
