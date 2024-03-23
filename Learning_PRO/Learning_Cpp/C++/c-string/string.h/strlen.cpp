#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	fgets(s,sizeof s,stdin);
	size_t len=strlen(s)-1;
	printf("%d\n",len);
	printf("%d\n",strlen(s)-1);
//strlen(s)-1 do ham fgets() doc ca ki tu '\n'
	gets(s);
	size_t len2=strlen(s);
	printf("%d %d",len2,strlen(s));
}
