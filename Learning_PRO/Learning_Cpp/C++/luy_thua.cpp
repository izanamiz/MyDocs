#include<iostream>

using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	int pro=1;
	//for (; b > 0; pro *= a, b--);
	while(b--)
	{
		pro*=a;
	}	
	cout<<pro;	
}
	
	

