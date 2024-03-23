#include<bits/stdc++.h>
using namespace std;
int k, m, n;
int b[30]={0};
bool ok=false;
void in() {
    for(int i=1; i<=n; i++) cout << b[i] << " ";
    cout << endl;
}
int checkm() {
    int c=0;
    int cm=0;
    for(int i=1; i<=n; i++) {
        if(b[i]==1) c++;
        else c=0;
        if(c==m) cm++;
        if(c>m) return 0;
    }
    if(cm==1) return 1;
    else return 0;
}
int checkk() {
    int c=0;
    int ck=0;
    for(int i=1; i<=n; i++) {
        if(b[i]==0) c++;
        else c=0;
        if(c==k) ck++;
        if(c>k) return 0;
    }
    if(ck==1) return 1;
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
    cin >> k >> m >> n;
    while(!ok) {
        if(checkk() && checkm()) in();
        sinh();
    }
}