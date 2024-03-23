//find all prime numbers in a range  [L,R] (R can be very large)
#include<iostream>
#include<vector>
typedef  long long ll;
using namespace std;
  
int main(){
	ll L, R; cin >> L >> R;
	vector<bool> isPrime(R - L + 1, true);
	// x là so nguyen to khi và chi khi 
	// isPrime[x - l] == true
    for (ll i=2; i*i <= R; i++)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
 /* if (1 >= L) {  // Xét riêng truong hop so 1
    	isPrime[1 - L] = false;
*/
	for (long long x = L; x <= R; ++x) {
	    if (isPrime[x - L]) {
	        // i là so nguyên to
	        cout << x << ' ';
	    }
	}
}


