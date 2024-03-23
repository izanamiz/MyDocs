#include<bits/stdc++.h>
using namespace std;
void printHello(int n)
{
	cout<<"Hello "<<n<<endl;
}
bool isPrime(int n){
	if(n<2) return false;
	for(int i=2;i<sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n;cin>>n;
	printHello(n);
	cout<<&n;
	if(isPrime(n)){
		cout<<"YES";
	}else cout<<"NO";
}
