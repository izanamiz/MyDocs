#include<stdio.h> //khai bao public
int main()
{
	int n=(5<3)+3;	//	9%4 chia lay phan du
	 			//  9/4 chia nguyen
	int m='9' -'0'; 			
	float x=5.9, h[2]={2,4.9};
	char y='C'+2;
	char z[10]="Ab";//z[0]='A''z[1]='b';z[2]='\0'
	printf("%d %d %f %c %s ",n,m,x,y,z);
	printf("\n h[2]=%f %f",h[0],h[1]);
}
