#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int count=0,i=2;
	int k=1;
	while(n>=i)
	{
		while(n%i==0)
		{
			count++;
			n/=i;
		}
		k*=(count+1);
		i++;
		count=0;
	}
	cout<<k;		
}
	
	

