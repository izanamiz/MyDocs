 // Cho t test. Moi bo test cho so a, in ra so uoc cua a
 #include<bits/stdc++.h>
 #define ll long long
 #define Max 1000000
 using namespace std;
 vector<bool> dd;
 vector<int> nt;
// vector<int> pos(1e6+1);
 void sang()
 {
 	for(ll i=2; i*i<=Max; i++)
 	{
 		if(dd[i] == 0)
 		{
 			for(ll j=i*i; j<=Max; j+=i) dd[j] = 1;
 			nt.push_back(i);
 		}
 	//	pos[i] = nt.size()-1;
 	// pos[i] = nt.back(); // lay phan tu cuoi cung
	}
 }
 int main()
 {
 	int t; cin >> t;
 	dd.resize(1e6+1,0);
 	sang();
 	while(t--)
 	{
 		int l,r;
 		cin >> l >> r;
//		for(ll i=l; i<=r; i++)
//		{
//			if(dd[i] == 0) cout << i << ' ';
//		}
//		cout<<'\n';
		for(ll i=0; i<nt.size(); i++)
		{
			if(nt[i] >= l && nt[i] <= r) cout << nt[i] <<' ';
		//	pos[i] = j  so nguyen to gan i co chi so la j;
		}
		
		cout << '\n';
	 }
	
	return 0;
 }
