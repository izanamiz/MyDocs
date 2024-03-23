#include<iostream>
#include<vector>
#define ll long long
using namespace std;

bool checkPrime(ll x){
	if(x<2 ) return false;
	for(ll i=2; i*i<=x; i++)
		if(x%i==0) return false;
	return true;	
		
}
ll fSum(ll x){
	ll sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}

	return sum;
}

ll f(ll x){
	if(x==1) return 1;
	if(checkPrime(x)) return fSum(x);
	ll pro=1;
	for(ll i=2; i<x; i++){
		if(x%i==0) pro*=f(i);
	}
	return pro;
}

int main(){
	int n; cin>>n;
	cout<<f(n);
	
}
