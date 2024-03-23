#include<stdio.h>
int t,n, a[105];

int giamdan()
{
	int i=0;
	while(a[i] > a[i+1] && i<n-1)
	{
		i++;
	}
	if(i == n-1) return 1;
	return 0;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}	
		if(giamdan()) printf("Yes\n");
		else printf("No\n");
	}
}
