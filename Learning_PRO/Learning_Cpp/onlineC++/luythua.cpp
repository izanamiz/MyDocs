#include<iostream>
#include<math.h>
using namespace std;

/*long long luythua(int n,int k){
    if(k==0) return 1;
    return luythua(n,k-1) *n;
}*/
/*
a^b = a^(b/2))*(a^(b/2) if b even
a^b= a^(b/2)*a^(b/2)*a if b odd
*/
long long luythua(long long n,long long t){
    if(t==0) return 1;
    if(t==1) return n;
    long long m=luythua(n,t/2);
    if(t%2==0) return m*m;
    return m*m*n;
}
int main(){
	int n,k;
	cin>>n>>k;
    cout<<luythua(n,k);
}

