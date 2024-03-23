#include<bits/stdc++.h>
using namespace std;
int n;
int c[30][30];
int a[30], b[30];
int cost=INT_MAX;
vector<int> v;
void luu() {
    v.clear();
    for(int i=1; i<=n; i++) v.push_back(a[i]);
    v.push_back(a[1]);
}
int check() {
    int sum=0;
    for(int i=1; i<=n-1; i++) {
        if(c[a[i]][a[i+1]]==0) return 0;
        else sum+=c[a[i]][a[i+1]];
    }
    sum+=c[a[n]][a[1]];
    if(sum<cost) {
        cost=sum;
        return 1;
    }
    else return 0;
}
void Try(int i) {
    for(int j=1; j<=n; j++) {
        if(b[j]==0) {
            a[i]=j;
            b[j]=1;
            if(i==n) {
                if(check()) luu();
            }
            else Try(i+1);
            b[j]=0;
        }
    }
}
int main() {
    cin >> n;
    int cmin=INT_MAX;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> c[i][j];
        }
    }
    Try(1);
    cout << cost << ".0" << endl;
    for(int i=0; i<=n; i++) cout << v[i] << " ";
}