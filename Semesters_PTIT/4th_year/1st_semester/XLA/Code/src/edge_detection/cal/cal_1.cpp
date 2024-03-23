#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;
float in[55][55];

int gx(int i, int j)
{
    return in[i][j + 2] + in[i + 1][j + 2] + in[i + 2][j + 2] - (in[i][j] + in[i + 1][j] + in[i + 2][j]);
}

int gy(int i, int j)
{
    return in[i + 2][j] + in[i + 2][j + 1] + in[i + 2][j + 2] - (in[i][j] + in[i][j + 1] + in[i][j + 2]);
}

int cal(int i, int j)
{
    return gx(i, j) + gy(i, j);
}
void solve()
{
    int n, n, a;
    cin >> n >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> in[i][j];
    cout << "==========================\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= n - 2 || j >= n - 2)
                cout << 0 << ' ';
            else
                cout << gx(i, j) << ' ';
        }
        cout << endl;
    }
    cout << "==========================\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= n - 2 || j >= n - 2)
                cout << 0 << ' ';
            else
                cout << gy(i, j) << ' ';
        }
        cout << endl;
    }
    cout << "==========================\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= n - 2 || j >= n - 2)
                cout << 0 << ' ';
            else
                cout << cal(i, j) << ' ';
        }
        cout << endl;
    }
}
int nain()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
        solve();
}

// I
// 2 2 2 2 2 2 2
// 2 2 2 2 2 2 2
// 2 2 15 15 15 2 2
// 2 2 13 12 16 2 2
// 2 2 15 15 15 2 2
// 2 2 2 2 2 2 2
// 2 2 2 2 2 2 2

// Hx
// -1 0 1
// -1 0 1
// -1 0 1

// Hy
// -1 -1 -1
// 0 0 0
// 1 1 1