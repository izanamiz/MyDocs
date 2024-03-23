#include <bits/stdc++.h> 
using namespace std; 

bool compare(pair<int,int> &p1,pair<int, int> &p2) 
{ 
    if (p1.second == p2.second) 
        return (p1.first < p2.first); 
    return (p1.second > p2.second); 
} 

void printSorted(int arr[], int n) 
{ 
    
    map<int, int> m; 
    for (int i = 0; i < n; i++) 
        m[arr[i]]++;
    int s = m.size(); 
    pair<int, int> p[s]; 
    int i = 0; 
    for (auto it = m.begin(); it != m.end(); ++it) 
        p[i++] = make_pair(it->first, it->second); 
    
    sort(p, p + s, compare); 
    for (int i = 0; i < s; i++) 
    { 
        int freq = p[i].second; 
        while (freq--) 
            cout << p[i].first << " "; 
    } 
} 
int main() 
{ 
    int t,n,i;
    cin >> t;
    while(t--)
    {
    	cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++)
	    cin >> arr[i]; 
	    printSorted(arr, n);
	}	 
    return 0; 
} 
