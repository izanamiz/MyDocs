#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef int* pint;

int main()
{
    // 2 cách
    // kiểu dữ liệu* biến
    // kiểu dữ liệu *biến
    //int *px;
    pint px;
    int y = 8, z = 10;
    px = &y; // <=> *px = y;
    cout << *px << " " << y << '\n';
    // px thay đổi thì y thay đổi
    *px = *px + 10 ;
    cout << *px <<" "<< y << '\n';
    // con trỏ chỉ vào đâu, lấy giá trị ở đấy
    px = &z;
    cout << *px << " " << y;

}