#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[31];
    int dem=0;
    for(int i=0; i<n; i++) cin >> a[i];
    while(next_permutation(a,a+n)) {
        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;
        dem++;
        if(dem==k) break;
    }
}