#include<iostream>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int dem=0,dd=0;
		
	for(int i=2;i<=n;i+=2)
	{
		int j=i;
		dd=0;
		while(j%2==0)
		{
			if(j%2==0){
				dem++;
				if(dem>=k)
				{
					dd=1;
					cout<<"Yes";
					return 0;
				}
				j/=2;
			}
		}
	}
	if(dd==0)
			cout<<"No";
	return 0;
}

