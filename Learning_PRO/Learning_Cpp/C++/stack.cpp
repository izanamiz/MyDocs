#include<iostream>
using namespace std;
void printArray1(int a[], int n)
{
	if (n == 0)
		return;
	else
	{
		printArray1(a, n - 1);
		cout << a[n - 1] << " ";
	}
}

/*Cách 2*/
void printArray2(int a[], int n)
{
	if (n == 0)
		return;
	else
	{ 
        cout << a[n - 1] << " ";
		printArray2(a, n - 1);
		
	}
}
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printArray1(a, 10);
    printArray2(a, 10);
	system("pause");
	return 0;
}
