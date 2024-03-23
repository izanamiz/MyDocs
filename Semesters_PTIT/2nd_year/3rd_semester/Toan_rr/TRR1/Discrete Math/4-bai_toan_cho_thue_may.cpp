#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[31];
int c[31][31];
int kq=INT_MIN;
vector<int> v;
void luu() {
    for(int i=1; i<=n; i++) v.push_back(a[i]);
}
int check() {
    int b[31]={0};
    int day=0;
    for(int i=1; i<=n; i++) {
        if(a[i]==1) {
            for(int j=1; j<=k; j++) {
                if(c[i][j]==1) {
                    if(b[j]==1) return 0;
                    else if(b[j]==0) {
                        b[j]=1;
                        day++;
                    }
                }
            }
        }
    }
    if(day>kq) {
        kq=day;
        v.clear();
        return 1;
    }
    else if(day==kq) return 1;
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
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            cin >> c[i][j];
        }
    }
    Try(1);
    int count=0;
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
        count++;
        if(count==n) {
            cout << endl;
            count=0;
        }
    }
}