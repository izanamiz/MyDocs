#include<bits/stdc++.h>
using namespace std;
int n,k;
int c[30];
void in() {
    for(int i=1; i<=k; i++) cout << c[i] << " ";
    cout << endl;
}
void Try(int i) {
    for(int j=c[i-1]+1; j<=n-k+i; j++) {
        c[i]=j;
        if(i==k) in();
        else Try(i+1);
    }
}
int main() {
    cin >> k >> n;
    Try(1);
}