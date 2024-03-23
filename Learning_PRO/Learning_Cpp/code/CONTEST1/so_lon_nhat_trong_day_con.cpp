#include<iostream>
#include<climits>

using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n],max;
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		for(int i=0;i<n-k+1;i++)
		{
			max=INT_MIN;
			for(int j=i;j<i+k;j++)
			{	
				if(a[j]>max)
					max=a[j];	
			}
			cout<<max<<" ";
		}
		cout<<endl;	
	}
	return 0;
}
