#include<bits/stdc++.h>
using namespace std;

int sumN(int n){
	if(n==0) return 0;
	return n+sumN(n-1);
}
//sum(1->5)=5+sum(1->4)=5+4+sum(1->3)
long long factor(long long n){
	//Diem dung
	if(n==0) return 1;
	else return n*factor(n-1);
}
int fibo(int n)
{
	if(n==1) return 0;
	if(n==2) return 1;
	return fibo(n-1) + fibo(n-2);
}
int main(){

	cout<<sumN(10)<<endl;
	cout<<factor(17)<<endl;
	cout<<fibo(5)<<endl;
	for(int i=1;i<6;i++){
		cout<<fibo(i)<<" ";
	}
	return 0;
}
