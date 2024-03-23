#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int c,m;
		cin>>c>>m;
		if(c%(m+1)==0)
			cout<<"Second"<<endl;
		else
			cout<<"First"<<endl;	
	}
}
