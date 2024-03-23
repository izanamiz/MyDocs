#include<bits/stdc++.h>

using namespace std;

long long a[100006];

long long lcm(long long a, long long b)
{
    return a*b/__gcd(a,b);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        cout << a[1] << " ";
        for(int i=1; i<n; i++)
            cout << lcm(a[i],a[i+1]) << " ";
        cout << a[n] << endl;
    }
}
