#include<stdio.h>
int ktra(int n){
	int s=1;
	for( int i=2;i*i<=n;i++){
		if(n%i==0){
			s=s+i+n/i;
		}
	}
	if(s==n){
		return 1;
	}	
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for( int i=2;i<n;i++){
		if(ktra(i)==1){
			printf("%d ",i);
		}
	}
}
