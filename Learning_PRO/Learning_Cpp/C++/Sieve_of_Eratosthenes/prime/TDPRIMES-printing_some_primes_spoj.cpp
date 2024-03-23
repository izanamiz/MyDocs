#include<iostream>
#include<vector>
#include<algorithm>
#define Max 100000000
#define ll long long
using namespace std;
int main()
{
	vector<char> isPrime(Max+1, true);
	isPrime[0] = isPrime[1] = false;
	for(int i=2; i*i<=Max; i++)
	{
		if(isPrime[i])
		{
			for(int j= i*i; j<=Max; j+=i)
				isPrime[j]=false;				
		}
	}
	ll count =0;

	for(int i=1; i<=Max; i++)
	{
		if(isPrime[i]) {
			count++;
			if(count % 100 == 1) cout <<i <<'\n';	
		}
	}
}
