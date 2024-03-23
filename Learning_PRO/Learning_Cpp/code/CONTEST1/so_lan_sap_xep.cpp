#include <bits/stdc++.h>
using namespace std;

int main()
{
	const int m=300000;
	int a[m], n;
	cin>>n;
	for (int i=1; i<=n; i++)
		cin>>a[i];
	int dem=0, k=n;
	for (int i=n; i>=1; i--)
	{
		if (a[i]!=k)
			dem++;
		else
			k--;
	}
	cout<<dem;
	return 0;
}
    
