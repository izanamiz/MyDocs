#include<stdio.h>
int main(){
//	char name1[]={"ProPTIT"};
//	char name2[]={'P','r','o','P','T','I','T','\0'};
//	printf("%s\n",name1);
//	printf("%s\n",name2);
	//	int x[50];
//gets(x);	
// fgets(<ten bien>,<so luong ki tu toi da nhap vao>,<luong vao>);	
	//fgets(x,sizeof(x),stdin);//read "Cau lac bo\n\'0'"
//	scanf("%s",x);//khong nhap duoc dau cach

	char name[50];
	int tuoi;
	scanf("%d",&tuoi);
//	fflush(stdin); hay bi loi
	fgets(name,sizeof(name),stdin);
	fgets(name,sizeof(name),stdin);
	
	printf("tuoi: %d\n",tuoi);
	printf("ten: %s",name);
	
}
