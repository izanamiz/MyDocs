#include<bits/stdc++.h>

using namespace std;

int main() 
{ 
    int t;
	cin>>t;
	while(t--)
	{
		int N;
		long long K;
		cin>>N>>K;
		long long a[N];
		
		for(int i=0;i<N;i++)	
			cin>>a[i];
	    
		sort(a,a+N);
		long long count=0;
		for(int i=0;i<N;i++)
		{
			int j=i+1,k=N-1;
			while(j<k){
				if(a[i]+a[j]+a[k]>=K)
					k--;
				else{
					count+=(k-j);
					j++;						
				}	
			}
		}
		cout<<count<<endl;
	} 
    return 0; 
} 

