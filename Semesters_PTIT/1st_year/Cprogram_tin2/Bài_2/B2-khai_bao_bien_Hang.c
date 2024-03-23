#include<stdio.h>
#define S "ABC" // khai bao hang
int x=100;		// khai bao public
void f(){
	// khai bao hang const
	const float y=20; // khai bao private
	printf("%s %d %f ",S,x,y);
	// return;
}
int main()
{
	f();
	printf("\n%d",x);
	printf("\n%s",S);
	
}
