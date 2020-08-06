// UVa 11729 Commando War
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

// greedy heuristic: sort by greater<|Ji|> 
// As max(Bx+Jx, Bx+By+Jy) <= max(By+Jy, By+Bx+Jx) when Jx >= Jy
const int maxn = 10005;
struct Node
{
    int b, j;
    bool operator < (const Node &rhs) const { return j > rhs.j; }
} nodes[maxn];

int main()
{
    int n, kase = 0;
    while(cin >> n && n)
    {
        int agg = 0, ans = 0;
        for(int i = 0; i < n; i++)
            cin >> nodes[i].b >> nodes[i].j;
        sort(nodes, nodes+n);
        for(int i = 0; i < n; i++)
        {
            agg += nodes[i].b;
            ans = max(ans, agg + nodes[i].j);
        }
        cout << "Case " << ++kase << ": " << ans << endl;
    }
    return 0;
}
