#include<stdio.h>
int n, a[105];
int dd[105]={0};
void vao()
{
	FILE *f1 = fopen("in.txt","r");
	fscanf(f1,"%d",&n);
	for(int i=0; i<n; i++) fscanf(f1,"%d",&a[i]);
	fclose(f1);
}
void ghitep()
{
	FILE *f2 = fopen("out.txt","w");
	for(int i=0; i<n; i++)
	{
		if(dd[i] == 1) continue;
		int cnt = 0;
		for(int j=i; j<n; j++)
		{
			if(a[i] == a[j])
			{
				dd[j]=1;
				cnt++;				
			}
		}
		fprintf(f2, "%d xuat hien %d lan\n", a[i], cnt);
	}

//	1	3	1	2	2	1
	
	
	fclose(f2);
}
int main()
{
	vao();
	ghitep();	
}
