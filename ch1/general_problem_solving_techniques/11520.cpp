// UVa 11520 Fill the Square
// wangqc
#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 15;
char mat[maxn][maxn];

int n;

// greedy, fill each slot with the smallest valid character
int main()
{
    int T;
    cin >> T;
    for(int kase = 1; kase <= T; kase++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> mat[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) if(mat[i][j] == '.')
                for(int c = 'A'; c <= 'Z'; c++)
                {
                    bool ok = true;
                    if(i > 0 && mat[i-1][j] == c) ok = false;
                    if(i < n-1 && mat[i+1][j] == c) ok = false;
                    if(j > 0 && mat[i][j-1] == c) ok = false;
                    if(j < n-1 && mat[i][j+1] == c) ok = false;
                    if(ok) { mat[i][j] = c; break; }
                }
        cout << "Case " << kase << ":\n";
        for(int i = 0; i < n; i++)
            cout << mat[i] << endl;
    }
    return 0;
}
