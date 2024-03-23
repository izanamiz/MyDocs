#include<iostream>

using namespace std;

int main() 
{ 
		int n,k;
		cin>>n>>k;
		int a[n],j=1;

		for(int i=0;i<n;i++){
			a[i]=j;	
			j++;
		}	

		long long sum=a[0];
		int dem=0,start=0;
		for(int i=1;i<=n;i++)	
		{
			while(sum>k && start<i-1){
				sum=sum-a[start];
				start++;
			}
			if(sum==k)
				dem++;
			if(i<n)
				sum+=a[i];
		}
		cout<<dem;
    return 0; 
} 
