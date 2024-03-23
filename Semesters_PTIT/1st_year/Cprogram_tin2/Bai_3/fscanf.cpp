#include<stdio.h>
#include<fstream>
#include<math.h>

int main()
{
	FILE *f2=fopen("C:\\n5.txt","r"); //doc read
	int i;
	char x[20]="Abc";
	float z[3]={1,2,3};
	fscanf(f2,"%d%f",&i,&z[1]);
	fflush(stdin);
	fgets(x,sizeof(x),stdin);
	fflush(stdin);
	fclose(f2);
	printf(" i=%d \n z[1]=%f\n x=%s \n ",i,z[1],x);
}
