#include<stdio.h>
#include<stdlib.h>
int main(){
	char num1[]="12345";
	int numInt=atoi(num1);
	long numLong=atol(num1);
	float numFloat=atof(num1);
	
	char num2[]="abcde";
	int Int=atoi(num2);
	long Long=atol(num2);
	float Float=atof(num2); 
			
	printf("%d %ld %f\n",numInt,numLong,numFloat);
	printf("%d %ld %lf",Int,Long,Float );

}
