// UVa 11825 Hackers' Crackdown
// wangqc
#include<iostream>

using namespace std;
const int maxn = 16;
int p[maxn], cover[1<<maxn], dp[1<<maxn];

int main()
{
    int n, m, kase = 0;
    while(cin >> n && n)
    {
        int ALL = (1<<n)-1;
        for(int i = 0; i < n; i++)
        {
            cin >> m;
            int x;
            p[i] = 1<<i;
            while(m--)
            {
                cin >> x;
                p[i] |= 1<<x;
            }
        }
        // cover[U(nodes)] = U(neighbor nodes)
        for(int s = 0; s <= ALL; s++)
        {
            cover[s] = 0;
            for(int i = 0; i < n; i++)
                if(s & (1<<i)) cover[s] |= p[i];
        }
        dp[0] = 0;
        for(int s = 1; s <= ALL; s++)
        {
            dp[s] = 0;
            for(int sub = s; sub; sub = (sub-1)&s) if(cover[sub]==ALL)
                dp[s] = max(dp[s], dp[s^sub]+1);
        }

        cout << "Case " << ++kase << ": " << dp[ALL] << endl;
    }
    return 0;
}
