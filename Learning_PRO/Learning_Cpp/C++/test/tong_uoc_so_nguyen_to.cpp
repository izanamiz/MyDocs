#include<bits/stdc++.h>
#define MAX 10000005
#define ll long long
#define size 10000005
using namespace std;
vector <bool> dd(1e7+5,1);
int b[size] = {0};
void sang()
{
	for(ll i=2;i*i<=MAX;i++)
	{
		if(dd[i])
		{
			for(ll j=i;j<=MAX;j+=i)
			{
				dd[j]=0;
				b[j]++;
			}
		}
	}
	for(int i=2; i<=MAX; i++) b[i] += b[i-1];
}
int main()
{
	sang();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--)
	{
		ll l,r;
		cin >> l >> r;
		cout << b[r] - b[l-1] << '\n';
	}
	return 0;
}
