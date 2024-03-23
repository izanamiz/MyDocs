#include <iostream>

using namespace std;

int b[1000000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
	    int a[n];
	    for (int i=0 ; i<n ; i++)
	    {
			cin>>a[i];
			b[a[i]]++;
		}
		for (int i=1 ; i<1000000 ; i++)
		{
			if(b[i]%2!=0)
			{
				cout<<i<<endl;
			}
		}

	}
	
}
