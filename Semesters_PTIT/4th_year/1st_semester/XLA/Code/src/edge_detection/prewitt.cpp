#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;
float in[55][55];
int gx(int i, int j)
{
    return in[i + 1][j - 1] + in[i + 1][j] + in[i + 1][j + 1] - (in[i - 1][j - 1] + in[i - 1][j] + in[i - 1][j + 1]);
}
int gy(int i, int j)
{
    return in[i + 1][j + 1] + in[i][j + 1] + in[i - 1][j + 1] - (in[i - 1][j - 1] + in[i][j - 1] + in[i + 1][j - 1]);
}
int cal(int i, int j)
{
    return sqrt(gx(i, j) * gx(i, j) + gy(i, j) * gy(i, j));
}
void solve()
{
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> in[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1 || i == n || j == n)
                cout << 0 << ' ';
            else
                cout << cal(i, j) << ' ';
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
        solve();
}

// 2 2 2 2 2 2 2
// 2 2 2 2 2 2 2
// 2 2 15 15 15 2 2
// 2 2 13 12 16 2 2
// 2 2 15 15 15 2 2
// 2 2 2 2 2 2 2
// 2 2 2 2 2 2 2

// 0 0 0 0 0 0 0
// 0 26 39 39 13 0 0
// 0 35 44 38 1 -13 0
// 0 37 36 3 -36 -40 0
// 0 13 2 -32 -47 -41 0
// 0 0 -13 -39 -39 -26 0
// 0 0 0 0 0 0 0