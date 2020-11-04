// UVa 1394 And Then There Was One
// wangqc
#include<iostream>

using namespace std;

const int maxn = 10005;
int f[maxn];

// f(n) = (f(n-1)+k) % n, f(1) = 0
// after each removal reindex the rest elements, after: i, before: (i+k)%n, trace backwards

int main()
{
    int n, k, m;
    while(cin >> n >> k >> m && n)
    {
        for(int i = 2; i <= n; i++)
            f[i] = (f[i-1] + k) % i;
        int ans = (m - k + 1 + f[n]) % n;
        if(ans <= 0) ans += n;
        cout << ans << endl;
    }
    return 0;
}
