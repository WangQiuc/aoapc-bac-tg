// UVa 1267 Network
// wangqc
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 1005;
vector<int> g[maxn], nodes[maxn];
int n, s, k, parent[maxn];
bool covered[maxn];

void build(int x, int p, int d)
{
    parent[x] = p;
    if(g[x].size() == 1 && d > k)   // leave cannot be covered by root
        nodes[d].push_back(x);
    for(int y : g[x]) if(y != p)
        build(y, x, d+1);
}

void dfs(int x, int p, int d)
{
    covered[x] = true;
    for(int y : g[x]) if(y != p && d < k)
        dfs(y, x, d+1);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> s >> k;
        for(int i = 1; i <= n; i++)
            g[i].clear(), nodes[i].clear();
        for(int i = 0; i < n-1; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        build(s, -1, 0);
        int cnt = 0;
        memset(covered, 0, sizeof(covered));
        for(int d = n-1; d > k; d--)
            for(int y : nodes[d]) if(!covered[y])
            {
                int x = y;
                for(int j = 0; j < k; j++)  // place a server at y's kth grandparent
                    x = parent[x];
                dfs(x, -1, 0);
                cnt++;
            }
        cout << cnt << endl;
    }
    return 0;
}
