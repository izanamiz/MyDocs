#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(t--)
	{
		scanf("%d",&n);
		long long S=(long long) n*(n+1)/2;
		printf("%lld\n",S);
	}
}
