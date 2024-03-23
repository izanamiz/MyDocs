#include<bits/stdc++.h>
using namespace std;
int n, m;
int x;
int b[30]={0};
bool k=false;
void in() {
    for(int i=1; i<=m+n; i++) {
        if(b[i]) cout << "V" << " ";
        else cout << "H" << " ";
    }
    cout << endl;
}
int check() {
    int sum=0;
    for(int i=1; i<=x; i++) sum+=b[i];
    if(sum==n) return 1;
    else return 0;
}
void sinh() {
    int i=x;
    while(b[i]==1) {
        b[i]=0;
        i--;
    }
    if(i==0) k=true;
    else b[i]=1;
}
int main() {
    cin >> n >> m;
    x=m+n;
    while(!k) {
        if(check()) in();
        sinh();
    }
}