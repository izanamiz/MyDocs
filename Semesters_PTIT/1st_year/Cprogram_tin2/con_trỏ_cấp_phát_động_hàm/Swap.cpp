#include <iostream>
#define ll long long
using namespace std;

// void Swap(int &x, int &y)
// {
//     int tmp = x;
//     x = y;
//     y = tmp;
// }
void Swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
 
int main()
{
    int a = 2, b = 3;
    // Swap(a,b);
    Swap(&a,&b);
    cout << a << " " << b;

}