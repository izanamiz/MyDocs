#include<stdio.h>
#include<math.h>

int main()
{
	int i;
	char x[20]="Abc";
	float z[3]={1,2,3};
	scanf("%2d%f",&i,&z[1]);
//	fflush(stdin);
//	gets(x);
	fgets(x,sizeof(x),stdin);
	fgets(x,sizeof(x),stdin);
		printf(" i=%d \n z[1]=%f\n x=%s \n ",i,z[1],x);
}
