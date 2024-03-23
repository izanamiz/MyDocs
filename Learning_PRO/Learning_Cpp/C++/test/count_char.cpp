#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 10000005
typedef long long ll;
char str[size];
int main()
{
    ll n;
	char k;
	scanf("%d",&n);
	getchar();
	scanf("%c",&k);
    fgets(str, sizeof(str),stdin );
	fgets(str, sizeof(str),stdin );
	strupr(str);
	if('a'<=k && k<='z') k-=32;
	ll i=0;
	ll count=0;
	while(str[i]!='\0')
	{
		if(str[i]==k) count++;
		i++;
	}
	printf("%lld",count);

}
