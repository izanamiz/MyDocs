#include<stdio.h>
#include<string.h>
void upr(char s[]){ //ban chat la 1 con tro, tro den vi tri dau tien cua mang
	int i=0;
	while(s[i]!='\0'){
		if(s[i]>='a' && s[i]<='z')// c la chu in thuong
			s[i] = s[i]- 'a' + 'A';
		i++;	
	}	
}
void lwr(char *s){ //ban chat la 1 con tro, tro den vi tri dau tien cua mang
	int i=0;
	while(s[i]!='\0'){
		if(s[i]>='A' && s[i]<='Z')// c la chu in thuong
			s[i] = s[i]- 'A' + 'a';
		i++;	
	}	
}
void rev(char s[]){
	int l=0,r=strlen(s)-1;
	while(l<=r){
		char c=s[l];
		s[l]=s[r];
		s[r]=c;
		r--;l++;
	}
}

int main(){
// 1 so ham xu ly chuoi trong C:
/* 
	-strlen(<ten chuoi>) // lay doi dai chuoi chi tu '\0'
	- strupr(<ten chuoi>) //viet hoa tat ca cac ky tu
	- strlwr(<ten chuoi>) // viet thuong tat ca cac ky tu
	- strrev(<ten chuoi>) // lay dao nguoc chuoi
	- strcmp(s1,s2)		+) 0 neu s1==s2
						+) >0 neu s1>s2
						+) <0 neu s1<s2
	- strcat(s1,s2) -> noi chuoi s2 vao s1					
	- strcpy(s1,s2) -> copy s2 sang s1	
	- strtok(s,<ky tu muon tach>) -> tach chuoi dua vao 
*/		
//	char d[50];
//	fgets(d,sizeof(d), stdin);
//	int len=strlen(d);
//	int len=strlen(s); 
//	printf("%d\n",len);
	
//	printf("%s\n",strupr(c));
//	char s[50]="ProPTIT";
//	upr(s);	printf("%s\n",s);
//	lwr(s);	printf("%s\n",s);
//	rev(s);	printf("%s\n",s);
	char s1[]="123456 xyz qwer";
	char S[50][50];
//	char s2[]="abcxyz";
//	printf("%d\n",strcmp(s1,s2));
//	printf("%s\n",strcat(s1,s2));
//	printf("%s\n",strcpy(s1,s2));
	char* token;
	char x[2]=" ";
	int len=0;
	token= strtok(s1,x);
	while(token!=NULL){
		strcpy(S[len++],token);
		token=strtok(NULL,x);//strtok voi doi so dau la NULL nghia la tim token tiep theo			
	}
	for(int i=0;i<len;i++){
		strlwr(S[i]);
		S[i][0]-=('a'-'A');
	}
	for(int i=0;i<len;i++){
		printf("%s\n",S[i]);
	}

}
