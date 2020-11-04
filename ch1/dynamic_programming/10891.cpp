// UVa 10891 Game of Sum
// wangqc
#include<iostream>

using namespace std;

const int maxn = 105;
// d[i][j]: max score from [i, j]
// l[i][j] = min(d[i][j],...,d[j][j]) = min(d[i][j], l[i+1][j])
// r[i][j] = min(d[i][j],...,d[i][i]) = min(d[i][j], r[i][j-1])
int n, s[maxn], d[maxn][maxn], l[maxn][maxn], r[maxn][maxn];

int main()
{
    while(cin >> n && n)
    {
        for(int x, i = 1; i <= n; i++)
        {
            cin >> x;
            s[i] = s[i-1] + x;
            d[i][i] = l[i][i] = r[i][i] = x;
        }
        for(int j = 2; j <= n; j++)
            for(int i = j-1; i > 0; i--)
            {
                int m = min(0, min(l[i+1][j], r[i][j-1]));
                d[i][j] = s[j] - s[i-1] - m;
                l[i][j] = min(d[i][j], l[i+1][j]);
                r[i][j] = min(d[i][j], r[i][j-1]);
            }
        cout << d[1][n] * 2 - s[n] << endl;
    }
    return 0;
}
