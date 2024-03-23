#include<stdio.h>
int t,n, a[105];
int giamdan()
{
//	int i=0;
//	while(a[i] > a[i+1] && i<n-1)
//	{
//		i++;
//	}
//	if(i == n-1) return 1;
//	return 0;
	for(int i=0; i<n; i++)
		if(a[i] < a[i+1]) return 0;
	return 1;
}

void ghitep()
{
		FILE *f2 = fopen("daura.txt","a+");
		if(giamdan()) fprintf(f2,"YES\n");
		else fprintf(f2,"NO\n");
}
void doctep()
{
	FILE *f1 = fopen("dauvao.txt","r");
	FILE *f2;
	fscanf(f1,"%d",&t);
	while(t--)
	{
		fscanf(f1,"%d",&n);
		for(int i=0; i<n; i++) fscanf(f1,"%d",&a[i]);
//		if(giamdan()) printf("YES\n");
//		else printf("NO\n");
		ghitep();	
	}
	f2 = fopen("daura.txt","w");
	fclose(f1); //fclose(f2);
}

int main()
{
	doctep();	
}
