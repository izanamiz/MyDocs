#include<bits/stdc++.h>
using namespace std;
int n;
int a[30], b[30];
int dem=0;
void in() {
    for(int i=1; i<=n; i++) {
        if(dem<=4) cout << a[i] << " ";
    }
    if(dem<=4) cout << endl;
}
void Try(int i) {
    for(int j=1; j<=n; j++) {
        if(b[j]==0) {
            a[i]=j;
            b[j]=1;
            if(i==n) {
                dem++;
                in();
            }
            else Try(i+1);
            b[j]=0;
        }
    }
}
int main() {
    cin >> n;
    Try(1);
}