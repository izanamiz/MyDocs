#include<bits/stdc++.h>
using namespace std;
int a[30], b[30], c[30];
int n, k;
int kq=-1;
bool ok=false;
vector<int> v;
void luu() {
    v.clear();
    for(int i=1; i<=n; i++) v.push_back(a[i]);
}
int check() {
    int kg=0;
    int cost=0;
    for(int i=1; i<=n; i++) {
        if(a[i]==1) {
            kg+=b[i];
            cost+=c[i];
        }
    }
    if(kg<=k && cost>kq) {
        kq=cost;
        return 1;
    }
    else return 0;
}
void sinh() {
    int i=n;
    while(a[i]) {
        a[i]=0;
        i--;
    }
    if(i==0) ok=true;
    else a[i]=1;
}
int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) cin >> c[i];
    while(!ok) {
        if(check()) luu();
        sinh();
    }
    cout << kq << ".0" << endl;
    for(int i=0; i<n; i++) cout << v[i] << " ";
}