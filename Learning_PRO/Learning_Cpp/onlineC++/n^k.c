#include<iostream>
using namespace std;

long long luythua(long long k,long long n){
    if(k==1) return n;
    return luythua(n,k-1)*n;
}
int main(){
    int n,k;cin>>n>>k;
    cout<<luythua(k,n);
}
