#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
    ll n, k1 = 0;
    cin >> n;
    for (ll i = 1; i <= n; ++i){
        ll k = 0, a = i;
        for (ll j = 2; j <= i; ++j){
            if (a % j == 0){
                while (a % j == 0)
                    a /= j;
                k++;
            }
        }
        if (k == 2)
            k1++;
    }
    cout << k1;
    cout << "\n";
    }


