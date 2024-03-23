#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float x,y;cin>>x>>y;
	cout<<fmax(x,y)<<' '<<fmin(x,y)<<" "<<pow(x,y)<<" "<<exp(x)<<" "<<fmod(x,y);
//fmod(x, y)	Returns the floating point remainder of x/y
	cout<<endl<<hypot(x,y)<<endl;//Returns sqrt(x2 +y2) without intermediate overflow or underflow
	cout<<cbrt(x)<<" "<<cbrt(y);//Returns the cube root of x
	cout<<endl<<ceil(x)<<" "<<floor(y);
//ceil(x)	Returns the value of x rounded up to its nearest integer
//floor(x)	Returns the value of x rounded down to its nearest integer
}

