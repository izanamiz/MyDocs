#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m, n, rk;
    int l[5][5];
    int L;
    int nk[8] = {0};
    double prk[8], sk[8];

    cin >> m >> n;
    cin >> L;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> rk;
            l[i][j] = rk;
            nk[rk]++;
        }
    }
    
    for (int i = 0; i < L; i++)
    {
        prk[i] = double(nk[i]) / double((m * n));
    }

    double curr_sum = 0;
    for (int i = 0; i < L; i++)
    {
        curr_sum += prk[i];
        sk[i] = (L - 1) * curr_sum;
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << round(sk[l[i][j]]) << " ";
        }
        cout << endl;
    }
}
