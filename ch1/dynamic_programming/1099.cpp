// UVa 1099 Sharing Chocolate
// wangqc
#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 15, maxr = 105;

int n, R, C, a[maxn], S[1<<maxn], dp[1<<maxn][maxr];
bool vis[1<<maxn][maxr];

int bitcount(int s) { return s ? bitcount(s>>1)+(s&1) : 0; }

// dp(s,r,c) = (s'%r'==0 and dp(s-s',r-r',c) or (s''%c''==0 and dp(s-s'',r,c-c''))
// since s' = r'*c, s'' = r*c'', dp(s,x) = dp(s-s'/s'',x), x = r' and c''
bool dfs(int s, int x)
{
    if(vis[s][x]) return dp[s][x];
    vis[s][x] = true;
    int &ans = dp[s][x];
    if(bitcount(s) == 1) return ans = true;
    int y = S[s] / x;
    for(int s0 = s; s0; s0 = (s0-1)&s)
    {
        int s1 = s-s0;
        if(S[s0]%x == 0 && dfs(s0, min(x,S[s0]/x)) && dfs(s1, min(x,S[s1]/x)))
            return ans = true;
        if(S[s0]%y == 0 && dfs(s0, min(y,S[s0]/y)) && dfs(s1, min(y,S[s1]/y)))
            return ans = true;
    }
    return ans = false;
}


int main()
{
    int kase = 0;
    while(cin >> n && n)
    {
        int ALL = (1<<n)-1;
        cin >> R >> C;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        memset(S, 0, sizeof(S));
        for(int s = 0; s <= ALL; s++)
            for(int i = 0; i < n; i++) if(s & (1<<i))
                S[s] += a[i];
        memset(vis, 0, sizeof(vis));
        int ans;
        if(S[ALL] != R*C) ans = 0;
        else ans = dfs(ALL, min(R, C));
        cout << "Case " << ++kase << ": " << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}
