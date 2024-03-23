#include<bits/stdc++.h>
using namespace std;
int n;
int a[30], b[30], c[30][30];
vector<int> v;
int kq=INT_MAX;
void luu() {
    for(int i=1; i<=n; i++) v.push_back(a[i]);
}
int check() {
    int sum=0;
    for(int i=1; i<=n; i++) {
        sum+=c[i][a[i]];
    }
    if(sum<kq) {
        kq=sum;
        v.clear();
        return 1;
    }
    else if(sum==kq) return 1;
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
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> c[i][j];
        }
    }
    Try(1);
    int count=0;
    for(int i=0; i<v.size(); i++) {
        cout << "Man" << count+1 << "->Job" << v[i] << " || ";
        count++;
        if(count==n) {
            cout << endl;
            count=0;
        }
    }
}