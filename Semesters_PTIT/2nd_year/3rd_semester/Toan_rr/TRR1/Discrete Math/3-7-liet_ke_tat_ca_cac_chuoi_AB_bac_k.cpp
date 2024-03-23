#include<bits/stdc++.h>
using namespace std;
int m, n;
int b[30]={0};
bool ok=false;
void in() {
    for(int i=1; i<=n; i++) {
        if(b[i]==0) cout << "B" << " ";
        else cout << "A" << " ";
    }
    cout << endl;
}
int check() {
    int c=0;
    int x=0;
    for(int i=1; i<=n; i++) {
        if(b[i]==1) c++;
        else c=0;
        if(c==m) x++;
        if(c>m) return 0;
    }
    if(x==1) return 1;
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
    while(!ok) {
        if(check()) in();
        sinh();
    }
}