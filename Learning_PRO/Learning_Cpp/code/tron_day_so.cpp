#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,temp;
		cin>>n>>m;
		if(n<m)
		{
			temp=n,n=m,m=temp;
		}
		int tich=1,gt=1;
		

		for(int i=n+1-m+1;i<=n+1;i++)
			tich*=i;
		for(int i=1;i<=m;i++)
			gt*=i;
		
		cout<<((n+1)+tich/gt)<<endl;
		
	}
}
