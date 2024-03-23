#include<stdio.h>
#include<string.h>
#include<math.h>
int snt(int n){
	int i,j,k=0;
	if(n<2) return 0;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			k++;
			break;
		}
	}
	if(k==0) return 1;
	else return 0;
}
int tcs(int n){
	int b=0,c=1;
	while(n!=0){
		b=b+n%10;
		if(n%10!=2 && n%10!=3 && n%10!=5 && n%10!=7){
			c=0;
		}
		n/=10;
	}
	if(snt(b)&& c==1){
		return 1;
	}
	else return 0;
}

int main(){
	int a,b,i,j,k=0,max,min;
	scanf("%d %d",&a,&b);
	if(a>=b){
		max=a;
		min=b;
	}
	else{
		max=b;
		min=a;
	}
	for(i=min;i<=max;i++){
		if(snt(i) && tcs(i)){
			k++;
		}
	}
	printf("%d",k);

return 0;
}

