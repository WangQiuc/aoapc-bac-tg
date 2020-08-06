// UVa 11300 Spreading the Wealth
// wangqc
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;

const int maxn = 1000005;
ll c[maxn];
// xi: coin move from i to i-1, xi = x1-(Σai-iK)
// x1 is median in {Σai-iM}
int main()
{
    int n;
    while(cin >> n)
    {
        if(!n) { cout << 0 << endl; continue; }
        ll K, G, x, s = 0, ans = 0;
        cin >> c[0];
        for(int i = 1; i < n; i++)
        {
            cin >> c[i];
            c[i] += c[i-1];
        }
        K = c[n-1] / n, G = (n-1)*K;
        for(int i = n-1; i >= 0; i--, G -= K)
            c[i] -= c[0] + G;
        sort(c, c+n);
        x = c[n >> 1];
        for(int i = 0; i < n; i++)
            ans += abs(x-c[i]);
        cout << ans << endl;
    }
    return 0;
}
