#include<iostream>
#include<string>
#include<vector>
typedef long long ll;
using namespace std;

ll A[2005][2005];
int main()
{
	int n, m; cin >> n >> m;
	int i,j,k,s;
	for (i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			cin >> A[i][j];
			
	int x,y; cin >> x >> y;	

	s=n*2;
	for (i=1; i<=n; i++)
		for(k=n+1,j=n; k<=s,j>=1; k++,j--)
			A[i][k]=A[i][j];
	for (k=n+1,i=n; k<=s,i>=1; k++,i--)
		for(j=1; j<=s; j++)
			A[k][j]=A[i][j];
	
	int hang, cot;
	
	if(x % s == 0) hang = s;
	else hang = x % s;
	
	if(y % s == 0) cot = s;
	else cot = y % s;
	
	cout << A[hang][cot];

		
}
