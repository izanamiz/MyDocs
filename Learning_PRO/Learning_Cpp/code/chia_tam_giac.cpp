#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,h;
		scanf("%d%d",&n,&h);
		for(int i=1;i<n;i++)
		{
			double x=(double)h*sqrt((double) i/n);
			printf("%.6lf ",x);
		}
		printf("\n");
	}
}
