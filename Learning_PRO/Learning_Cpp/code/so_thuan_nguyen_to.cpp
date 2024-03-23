#include<iostream>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,c,x,y,S=0,k1=1,k2=1,k3=1,dem=0;
		cin>>a>>b;
		
	    if (a>b)
			c=a,a=b,b=c;
	    for (int n=a;n<=b;n++)
	    {
	    	for (int i=2;i*i<=n;i++)
			{
				if (n%i==0)
				{
					k1=0;
					break;
				}
			}
			if (k1==1)	
			{
				x=n;
				while(x)
				{
					y=x%10;
					if (y!=2 && y!=3 && y!=5 && y!=7)
					{
						k2=0;
						break;
					}
					S+=y;
					x/=10;		
				}
				if (k2==1)
				{
					for (int j=2;j*j<=S;j++)
					{
						if (S%j==0)
						{
							k3=0;
							break;
						}
					}
					if (k3==1)
					{
						dem++;
					}
					k3=1;
				}
				k2=1;
				S=0;
			}
			k1=1;
		}
		cout<<dem;
	}
	
}
