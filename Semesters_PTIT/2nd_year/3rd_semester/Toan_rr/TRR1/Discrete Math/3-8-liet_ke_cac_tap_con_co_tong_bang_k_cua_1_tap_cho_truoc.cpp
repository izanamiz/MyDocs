#include<bits/stdc++.h>
using namespace std;
int b[30]={0};
int m, n, a[30];
bool ok=false;
void in() {
    for(int i=1; i<=n; i++) {
        if(b[i]==1) cout << a[i] << " ";
    }
    cout << endl;
}
int check() {
    int sum=0;
    for(int i=1; i<=n; i++) {
        if(b[i]==1) sum+=a[i];
    }
    if(sum==m) return 1;
    else return 0;
}
void sinh() {
    int i=n;
    while(b[i]) {
        b[i]=0;
        i--;
    }
    if(i==0) ok=true;
    else b[i]=1;
}
int main() {
    cin >> m >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    while(!ok) {
        if(check()) in();
        sinh();
    }
}