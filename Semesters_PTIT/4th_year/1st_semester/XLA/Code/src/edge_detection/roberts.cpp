#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;
float in[55][55];
int cal(int i, int j)
{
    return sqrt((in[i][j] - in[i - 1][j - 1]) * (in[i][j] - in[i - 1][j - 1]) + (in[i][j - 1] - in[i - 1][j]) * (in[i][j - 1] - in[i - 1][j]));
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
    // cin >> t;
    while (t--)
        solve();
}