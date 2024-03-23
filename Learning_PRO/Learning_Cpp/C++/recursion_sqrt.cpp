#include<iostream>
#include<math.h>
using namespace std;
double SquareRoot(double n)
{
	double s=1;
	for(double i=2; i<=n; i++)
	{
		s=sqrt((double)i+SquareRoot(i-1));
	}
	return s;
}
int main()
{
	double n;cin>>n;
	cout<<SquareRoot(n);
}
