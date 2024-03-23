#include<iostream>
using namespace std;

const int MAX = 100000000;
bool prime[MAX];

int main()
{	
	for(int i = 2; i < MAX; i++)
		prime[i] = true;
	cout<< 2 << '\n';
	
	int cnt_prime = 1;
	int i;
	for(i = 3; i*i < MAX; i=i+2)
		if(prime[i])
		{
			cnt_prime++;
			if(cnt_prime % 100 == 1) cout<< i << '\n';
			
			int j = 3;
			while(i*j < MAX)
			{
				prime[i*j] = false;
				j += 2;
			}
		}
	for(int j = i; j < MAX; j+=2)
		if(prime[j])
		{
			cnt_prime++;
			if(cnt_prime % 100 == 1) cout<< j << '\n';
		}

	return 0;
}
