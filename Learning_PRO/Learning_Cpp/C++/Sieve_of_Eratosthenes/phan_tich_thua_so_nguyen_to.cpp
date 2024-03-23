// phan tich thua so nguyen to
#include<iostream>
#include<vector>
typedef  long long ll;
using namespace std;
  
int main(){
	int n; cin >> n;
	int minPrime[n + 1];
	for (int i = 2; i * i <= n; ++i) {
	    if (minPrime[i] == 0) { //if i is prime
	        for (int j = i * i; j <= n; j += i) {
	            if (minPrime[j] == 0) {
	                minPrime[j] = i;
	            }
	        }
	    }
	}
	for (int i = 2; i <= n; ++i) {
	    if (minPrime[i] == 0) {
	        minPrime[i] = i;
	    }
	}
	vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    for(int i=0 ; i<res.size(); i++)
    	cout << res[i] << ' ';
}
