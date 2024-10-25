#include <climits> 
#include <iostream> 
using namespace std; 
  
int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = 0, max_ending_here = 0; 
    for (int i = 0; i < size; i++) { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_ending_here < 0) 
            max_ending_here = 0; 

        else if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
    } 
    return max_so_far; 
} 

int main() 
{ 
    int t;
	cin>>t;
	while(t--)
	{
		int size;
		cin>>size;
		int a[size];
		for(int i=0;i<size;i++)	
			cin>>a[i];
	    int n = sizeof(a) / sizeof(a[0]); 
    	int max_sum = maxSubArraySum(a, n); 
    	cout << "Maximum contiguous sum is " << max_sum; 	
	} 

    return 0; 
} 
