#include<iostream>

using namespace std;

int a[2000000];
int main()
{
    int t,n, k;
    cin>>t;
    while(t--)
    {
    	cin>>n>>k;
	    k%=n;
	    for(int i = 1; i <= n; i++)
	    {
	        cin>>a[i];
	        a[i + n] = a[i];
	    }
	    for(int i = 1 + k; i <= n + k; i++) 
			cout<<a[i]<<" ";
	    cout<<endl;	
	}
    
	return 0;	
}
