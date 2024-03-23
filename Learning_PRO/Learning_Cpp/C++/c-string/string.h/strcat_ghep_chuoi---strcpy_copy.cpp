#include<stdio.h>
#include<string.h>
int main(){
	char str[]="Toi ten la: ";
	char s[100];
//copy gia tri cua chuoi nguon va luu vao chuoi dich	
// dung khi muon gan gia tri cua chuoi nay cho chuoi khac thay vi sd dau =
	strcpy(s,str);
	
//// ghep chuoi chuoi nguon vao phia sau chuoi dich	
	strcat(s,"Dong ");	
	strcat(s,"A ");
	strcat(s,"Van ");
	strcat(s,"Anh");
	puts(s);
}
