#include<stdio.h>
#include<string.h>
char a[105] ;
void doctep()
{
	FILE *f1 = fopen("dlvao.txt","r");
	fscanf(f1,"%s",&a);
	fclose(f1); 
}
int ktdx()
{

	int l = 0;
	int r = strlen(a)-1;
	int dd=1;
	while(l <= r)
	{
		if(a[l] == a[r])
		{
			l++;
			r--;
		}
		else return 0;
	}
	return 1;
}
void ghitep()
{
	FILE *f2 = fopen("dlra.txt","w");
	if(ktdx()) fprintf(f2,"YES\n");
	else fprintf(f2,"NO\n");
	fclose(f2);
}

int main()
{
	doctep();
	ghitep();
}
