#include<iostream>
#include<string>
#include<vector>
using namespace std;
int MOD(string a, int b){
	int carry=0;
	for(int i=0; i<a.size();i++){
		int k=a[i]-'0';
		carry=carry*10+k;
		carry%=b;
	}
	return carry%b;
}
int main(){
	cout<<MOD("1234",12);
}

