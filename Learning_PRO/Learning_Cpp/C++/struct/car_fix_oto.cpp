#include<iostream>
#include<vector>
#include<algorithm> 

typedef long long ll;
using namespace std;
struct oto
{	
	int a;
	int b;
	int id;

};
	int n;
//bool cmp(oto car1, oto car2)
//{
//	return (double) car1.a/car1.b > (double) car2.a/car2.b;
//}
	
int main(){
	cin >> n;
	vector<oto> v(n);
	for(int i=0; i<n; i++) cin >> v[i].a;
	for(int i=0; i<n; i++) 
	{
		cin >> v[i].b;
		v[i].id = i;
	}
//	sort(v.begin(), v.end(), cmp);	
	for(int i=0; i<n-1; i++){
		for(int j=i; j<n; j++)
		{
			if((double)v[j].a/v[j].b > (double) v[i].a/v[i].b)
				swap(v[i], v[j]);
		}
	}
	ll sum = 0;
	ll temp = 0;
	for(int i=0; i<v.size(); i++)
	{
		temp =(ll) temp + v[i].b;
		sum = (ll) sum + temp * v[i].a;
	}
	cout << sum << '\n';
	for(int i=0; i<v.size(); i++)
	cout << v[i].id + 1 << ' ';
	return 0;
	 
}
