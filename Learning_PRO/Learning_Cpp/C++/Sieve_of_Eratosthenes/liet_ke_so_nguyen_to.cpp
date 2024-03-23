// finding all the prime numbers in a segment [1,n]
#include<iostream>
#include<vector>
typedef  long long ll;
using namespace std;
  
int main(){
	int n; cin >> n;
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}
	for (int i = 1; i <= n; i++)
	{
		if (is_prime[i]) cout<< i <<' ';
	}
}
