#include<iostream>
#include<vector>
typedef  long long ll;
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		ll m,n;
		cin >> m >> n;
		vector<bool> isPrime(n-m+1, true );
		for(ll i = 2; i*i<= n; i++)
		{
			for (ll j = max(i * i, m + i - 1); j <= n; j += i)
            	isPrime[j - m] = false;
		}
		if(m <= 1) isPrime[1-m]=0;
		
		for(ll i = m; i<=n; i++)
		{
			if(isPrime[i-m]) cout << i <<'\n';
		}

	}
}
