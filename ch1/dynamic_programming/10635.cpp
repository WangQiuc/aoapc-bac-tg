// UVa 10635 Prince and Princess
// wangqc
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 250*250, inf = 0x3f3f3f3f;
int s[maxn], g[maxn], a[maxn];

// lcs(n^2) -> lis(nlogn)
int main()
{
    int T;
    cin >> T;
    for(int kase = 1; kase <= T; kase++)
    {
        int n, p, q, x, m = 0;
        cin >> n >> p >> q;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= p+1; i++)
        {
            cin >> x;
            a[x] = i;   // so that p -> range(1, x[p+1])
        }
        for(int i = 0; i < q+1; i++)
        {
            cin >> x;
            if(a[x]) s[m++] = a[x];
        }
        int ans = 0;
        memset(g, inf, sizeof(int)*(m+1));
        for(int i = 0; i < m; i++)
        {
            int k = lower_bound(g+1, g+m+1, s[i]) - g;
            g[k] = s[i];
            ans = max(ans, k);
        }
        cout << "Case " << kase << ": " << ans << endl;
    }
    return 0;
}
