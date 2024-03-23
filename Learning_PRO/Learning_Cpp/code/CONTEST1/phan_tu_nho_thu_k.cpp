#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k;cin>>n>>k;
	int a[n],temp[n],i,j=0; 
	for(i=0;i<n;i++)
		cin>>a[i];
		
	sort(a,a+n);
	for(i=0;i<n-1;i++)
		if(a[i]!=a[i+1]){
			temp[j]=a[i];
			j++;	
		}	
	temp[j]=a[n-1];	
	j++;
	if(k>j)
		cout<<-1;
	else
		cout<<temp[k-1];
	
		
}
