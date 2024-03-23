#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,dd=0;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int count;	
		for(int i=0;i<n;i++)
		{
			count=0;
			for(int j=i+1;j<n;j++)
			{
				if(a[i]==a[j])
					count++;
			}
			if(count!=0)
			{
				cout<<a[i]<<endl;
				break;	
			}		
		}
		if(count==0)
			cout<<"NO"<<endl;
			
	}
	return 0;
}
