// UVa 10859 Placing Lampposts
// wangqc
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 1005, M = maxn << 1;
int dp[maxn][2];
bool vis[maxn][2];
vector<int> g[maxn];

// node i with parent p, f = p has lamp
int dfs(int i, int f, int p)
{
    if(vis[i][f]) return dp[i][f];
    vis[i][f] = 1;
    int &ans = dp[i][f];
    // place lamp at i
    ans = M;
    for(int j : g[i]) if(j != p)
        ans += dfs(j, 1, i);
    if(!f && p != -1) ans++;
    
    // not place lamp at i
    if(f || p == -1)
    {
        int cnt = 0;
        for(int j : g[i]) if(j != p)
            cnt += dfs(j, 0, i);
        if(p != -1) cnt++;
        ans = min(ans, cnt);
    }
    return ans;
}

int main()
{
    int T, n, m;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++) g[i].clear();
        int x, y;
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < n; i++) if(!vis[i][0])
            ans += dfs(i, 0, -1);
        cout << ans/M << " " << m-ans%M << " " << ans%M << endl;

    }
    return 0;
}
