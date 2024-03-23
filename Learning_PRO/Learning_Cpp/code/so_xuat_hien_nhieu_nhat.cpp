#include <iostream>

using namespace std;

int a[1000000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
	    int b[n];
	    for (int i=0 ; i<n ; i++)
	    {
			cin>>b[i];
			a[b[i]]++;
		}
		int max=0,x=0;
		for (int i=1 ; i<100000 ; i++)
		{
			if(a[i]==max)
			{
				if (i>x);
				x=i;
			}
			else if(a[i]>max)
			{
				x=i;
				max=a[i];
			}
		}
		if(max> n/2)
			cout<<x<<endl;
		else
			cout<<"NO"<<endl;	
	}
	
}
