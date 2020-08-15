// UVa 11464 Even Parity
// wangqc
#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 20, inf = 1e9;
int n, a[maxn][maxn], b[maxn][maxn];

int check(int row)
{
    memset(b, 0, sizeof(b));
    for(int j = 0; j < n; j++)
    {
        if(row >> j & 1) b[0][j] = 1;
        else if(a[0][j]) return inf;                // cannot change 1 to 0
    }
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i > 1) b[i][j] ^= b[i-2][j];
            if(j) b[i][j] ^= b[i-1][j-1];
            if(j < n) b[i][j] ^= b[i-1][j+1];
            if(a[i][j] && !b[i][j]) return inf;     // cannot change 1 to 0 
        }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != b[i][j]) cnt++;
    return cnt;
}

// exhaustive search the first row and generate each row based on previous 2 rows
int main()
{
    int T;
    cin >> T;
    for(int kase = 1; kase <= T; kase++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        int ans = inf;
        for(int x = 0; x < (1<<n); x++)
            ans = min(ans, check(x));
        if(ans == inf) ans = -1;
        cout << "Case " << kase << ": " << ans << endl;
    }
    return 0;
}
