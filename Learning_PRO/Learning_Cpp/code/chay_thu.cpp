#include<iostream>
using namespace std;
int ts[1000000];
int main(){
	int t; cin>>t;
	while(t--){
	int n;cin>>n;
	int t=n/2;
	int a[n];
	int dem=0;;
	for (int i=0;i<n;i++){
		cin>>a[i];
		ts[a[i]]++;
	} 
	for (int i=0;i<n;i++)
	{
		if(ts[a[i]]>t) 
		{
			dem++;
		  	cout<<a[i]<<" ";
		  	break;
		}
	}
	for (int i=0;i<n;i++)
	{
	  	if(dem==0) 
		{
			cout<<"NO";
	    	break;	
		}   
	}
	cout<<endl;
}
}
