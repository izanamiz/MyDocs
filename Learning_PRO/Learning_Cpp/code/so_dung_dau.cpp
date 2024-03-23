#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t)
	{
		int n,dd=0;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			dd=0;
			for(int j=n-1;j>i;j--)
			{
				if(a[i]<=a[j])
				{
					dd=1;
					break;
				}
			}
			if(dd==0)
				cout<<a[i]<<" ";	
		}
		cout<<endl;
	}
	return 0;
}
