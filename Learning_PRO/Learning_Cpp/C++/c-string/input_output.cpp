#include<stdio.h>
int main(){
	char c[]={'a','b','c','d','\0'};
	printf("%s\n",c);
	char name[25];
	//scanf without " ",tab,\n
	//scanf: " "-> nhap nhieu input dong thoi
	scanf("%s",name);printf("%s\n",name);
	fflush(stdin);
	fgets(name,sizeof(name),stdin);//read string
	//gets(name); //khong nen dung do 
	// gets() k chi dinh kich thuoc toi da cua chuoi=> tran bo nho
	puts(name);//in them 1 dau \n o cuoi chuoi

}
