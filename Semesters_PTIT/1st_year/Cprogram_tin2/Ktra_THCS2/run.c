#include<stdio.h>
#include<math.h>
#define MAX 1000005
int arr[MAX];
int ktra(int n){
	int a = (int )sqrt(n);
	if(a*a==n){
		return 1;
	}
	return 0;
}

int main(){

	int a,b,dem=0,j=0;
	scanf("%d%d",&a,&b);
	for(int i=a; i<=b;i++)
	{
		if(ktra(i)==1){
			dem++;
			arr[j++]=i;
		}
	}
	printf("%d\n",dem);
	for(int i=0; i<j; i++){
		printf("%d\n",arr[i]);
	}


}
