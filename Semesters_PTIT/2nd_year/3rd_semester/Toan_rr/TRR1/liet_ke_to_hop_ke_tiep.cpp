#include<bits/stdc++.h>
using namespace std;
int dem=0;
int n, k, x;
int a[31];
bool ok=false;
void sinh() {
    int i=k;
    while(a[i]==n-k+i) i--;
    if(i==0 || dem==x-1) ok=true;
    else {
        a[i]++;
        for(int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
    }
}
int main() {
    cin >> n >> k >> x;
    for(int i=1; i<=k; i++) cin >> a[i];
    int dem=0;
    while(!ok) {
        sinh();
        dem++;
        for(int j=1; j<=k; j++) cout << a[j] << " ";
        cout << endl;
        if(dem==x) return 0;
    }
}