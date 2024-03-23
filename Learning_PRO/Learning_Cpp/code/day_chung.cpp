#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include "conio.h";
using namespace std;

// tìm max
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

//Hàm tìm dãy con chung l?n nh?t c?a 3 dãy
void LCSLength(string X, string Y, string Z)
{
	int i, j, k;
	int m = X.length(), n = Y.length(), o = Z.length();

	// X[0..i-1], Y[0..j-1], Z[0..k-1]
	//khai báo m?ng 3 chi?u làm b?ng phuong án
	int L[50][50][50];

	// Kh?i t?o giá tr? ban d?u cho b?ng phuong án
	/*memset(L, 0, sizeof L);*/
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			for (k = 0; k <= o; k++)
			{
				L[i][0][0] = 0;
				L[0][j][0] = 0;
				L[0][0][j] = 0;
			}
		}
	}
	// Duy?t t? d?u d?n cu?i m?ng 3 chi?u d? xây d?ng b?ng phuong án
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= o; k++)
			{
				// n?u ký t? hi?n t?i trùng nhau tr? v? nhu bên du?i
				if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1])
					L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;

				// n?u ký t? hi?n t?i dang xét không trùng nhau tr? v? giá tr? max
				else
					L[i][j][k] = max(max(L[i - 1][j][k], L[i][j - 1][k]), L[i][j][k - 1]);
			}
		}
	}
	//in ra d? dài dãy con chung
	//d? dài c?a dãy con s? là ph?n t? cu?i cùng trong b?ng phuong án
	cout << "Do dai day con chung la: " << L[m][n][o];
	cout << endl;
	//Truy v?t t? cu?i b?ng phuong án v? d?u d? tìm dãy con
	while (m > 0 && n > 0 && o > 0)
	{
		int step = L[m][n][o];
		if (X[m - 1] == Y[n - 1] && Y[n - 1] == Z[o - 1])
		{
			cout << step << ": " << X[m - 1] << endl;
			m--;
			n--;
			o--;
			step--;
		}
		else if (step == L[m - 1][n][o])
		{
			m--;
		}
		else if (step == L[m][n - 1][o])
		{
			n--;
		}
		else
		{
			o--;
		}
	}
}
int main()
{
	string X = "ABCBDAB", Y = "BDCABA", Z = "BADACB";
	LCSLength(X, Y, Z);
	_getch();
}
