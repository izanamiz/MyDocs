#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long long sum = 0, pro = 1;
	for (long long i = 1; i <= n; i++)
	{
		pro*= i;
		sum+= pro;
	}
	cout<<sum;
}

