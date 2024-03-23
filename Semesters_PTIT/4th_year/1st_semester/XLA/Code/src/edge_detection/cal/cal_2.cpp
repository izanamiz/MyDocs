#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;
float in[55][55];

int gz(int i, int j)
{
    return 4 * in[i + 1][j + 1] - (in[i][j + 1] + in[i + 1][j] + in[i + 1][j + 2] + in[i + 2][j + 1]);
}

int cal(int i, int j)
{
    return abs(gz(i, j));
}
void solve()
{
    int n, a;
    cin >> n;
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
                cout << gz(i, j) << ' ';
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
int main()
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

// Hz
// 0 -1 0
// -1 4 -1
// 0 -1 0
