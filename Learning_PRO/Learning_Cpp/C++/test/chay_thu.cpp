#include<stdio.h>
int dem(int n)
{
	int count = 0, i;
	for(i=1; i*i<n; i++)
	{
		if(n%i==0) 
		{
			if(i%2==0) count++;
			if((n/i) % 2 ==0) count++;
		}
				
	}
	if( i*i==n && i%2==0) count--;
	return count;
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int a;
		scanf("%d",&a);
		if(a<1 || a%2!=0) printf("0\n");
		else printf("%d\n",dem(a));
		
	}	
}
