#include<iostream>

using namespace std;
int main(){
	bool dung=true;
	bool sai=false;
	int x=60,y=13;
	int a=x>>3,b=x<<3,c=x&y,d=x|y,e=x^y;
	long long k;
	cout<<sizeof(a)<<" "<<sizeof(k);
	cout<<endl;
	cout<<(x>y?dung:sai);
	int i, j;
	j = 10;
	i = (j++, j+100, 999+j);//toan tu comma
	cout << endl<<i;
	}
