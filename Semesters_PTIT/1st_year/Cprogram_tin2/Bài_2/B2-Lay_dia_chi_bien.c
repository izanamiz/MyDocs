//Lay dia chi bien
#include<stdio.h>

int main()
{
	char s[10]="abc";
	printf("%c %c ",s[0],s[1]);
	s[0]='A';
	printf("\n%s",s);
	int x=5,y=10,*p;
	int a[3];
	p=&x; printf("\n x=%d, *p=%d",x,*p);
	p=&y; printf("\n y=%d, *p=%d",y,*p);	//1 con tro truy cap 2 bien
	*p=20;printf("\n y=%d, *p=%d",y,*p);
//	giaiptbac2(float a, float b, float c, float *x1)
//	giaiptbac2(1,5,2,&x1);		//x1 sau khi thuc hien xong nhan gia tri moi => dung con tro
}
// Ta chi co the lay dia chi cua 1 bien	
/*	
	int *p;
	const int m=10;
	pn=&m; 		//Dong lenh nay sai;
	int k;
	p=&(k+1);	//Dong lenh nay sai;
*/
	

