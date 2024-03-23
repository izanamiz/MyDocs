#include<stdio.h>
#include<fstream>

int main()
{
	// mo tep
	FILE *f1 = fopen("C:\\n5.txt","w"); //ghi de write
	int i=5 , j;
	char x[20]="Abc";
	float z[3]={1,2,3};
	j = i + 10;
	i+=1;
	fprintf(f1," j=%d \n i=%d\n x=%s \nz[1]=%f ",j,i,x,z[1]);
	// dong tep
	fclose(f1);
}
