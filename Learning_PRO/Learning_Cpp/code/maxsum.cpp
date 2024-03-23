#include<iostream>
#include <climits> 

using namespace std;

int main() 
{ 
    int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long a[n];
		
		for(int i=0;i<n;i++)	
			cin>>a[i];
	    
		long long sum=0,max=INT_MIN;
		for(int i=0;i<n;i++)	
		{
			sum+=a[i];
			if(sum<0)
				sum=0;
			if(max<sum)
				max=sum;
	
		}
		cout<<max<<endl;
	} 

    return 0; 
} 
