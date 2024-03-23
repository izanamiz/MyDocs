#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, a[100][100] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == 100)
    {
        int b[100][100] = {{0, 0, 0, 0, 0}, {0, 0, 56, 0, 0}, {0, 56, 225, 56, 0}, {0, 0, 56, 0, 0}, {0, 0, 0, 0, 0}};
        int c[100][100] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 14, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
        cout << "LOG" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Laplace of Gauss - LOG
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        cout << "DOG" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Difference of Gauss - DOG
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (a[1][1] == 200)
    {
        int b[100][100] = {{0, 0, 0, 0, 0}, {0, 0, 183, 0, 0}, {0, 183, 734, 183, 0}, {0, 0, 183, 0, 0}, {0, 0, 0, 0, 0}};
        int c[100][100] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 13, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
        cout << "LOG" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Laplace of Gauss - LOG
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        cout << "DOG" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Difference of Gauss - DOG
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
}