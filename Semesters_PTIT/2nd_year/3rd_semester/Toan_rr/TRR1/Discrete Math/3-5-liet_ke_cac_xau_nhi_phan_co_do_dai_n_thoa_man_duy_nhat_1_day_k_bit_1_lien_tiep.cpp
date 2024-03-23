#include<bits/stdc++.h>
using namespace std;
int k, n;
int b[30];
bool ok=false;
void in() {
    for(int i=1; i<=n; i++) cout << b[i] << " ";
    cout << endl;
}
int check() {
    int c=0;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=k+i-1; j++) {
            if(b[j]!=1) break;
            if(j==k+i-1 && b[j]==1) c++;
        }
    }
    if(c==1) return 1;
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
    cin >> k >> n;
    while(!ok) {
        if(check()) in();
        sinh();
    }
}