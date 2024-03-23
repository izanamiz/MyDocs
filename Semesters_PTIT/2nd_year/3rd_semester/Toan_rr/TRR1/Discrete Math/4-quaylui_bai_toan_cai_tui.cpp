#include<bits/stdc++.h>
using namespace std;
int a[30], b[30], c[30];
int n, k;
int kq=-1;
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
void Try(int i) {
    for(int j=0; j<=1; j++) {
        a[i]=j;
        if(i==n) {
            if(check()) luu();
        }
        else Try(i+1);
    }
}
int main() {
    cin >>  n >> k;
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) cin >> c[i];
    Try(1);
    cout << kq << ".0" << endl;
    for(int i=0; i<n; i++) cout << v[i] << " ";
}