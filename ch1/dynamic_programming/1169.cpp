// UVa 1169 Robotruck
// wangqc
#include<iostream>

using namespace std;

const int maxn = 100005;
// d[i]: d(i,0), pd[i]: ∑d(i-1,i), pw: ∑w(i), dq: monotonic queue
int d[maxn], pd[maxn], pw[maxn], dp[maxn], dq[maxn];

// dp[i] = min(dp[j]+d[j+1]+dist(j+1,i)+d[i]) | w(j+1,i) <= C
// dp[i] = min(dp[j]+d[j+1]+pd[i]-pd[j+1]+d[i]) = min(dp[j]+d[j+1]-pd[j+1])+pd[i]+d[i]
// put dp[j]+d[j+1]-pd[j+1] into dq

inline int f(int i) { return dp[i] + d[i+1] - pd[i+1]; }

int main()
{
    int T, C, n;
    cin >> T;
    while(T--)
    {
        cin >> C >> n;
        int x, y, w, px=0, py=0;
        for(int i = 1; i <= n; i++)
        {
            cin >> x >> y >> w;
            d[i] = x + y;
            pd[i] = pd[i-1] + abs(x-px) + abs(y-py);
            pw[i] = pw[i-1] + w;
            px = x, py = y;
        }
        int L = 1, R = 1;
        for(int i = 1; i <= n; i++)
        {
            while(pw[i]-pw[dq[L]] > C)
                L++;
            dp[i] = f(dq[L]) + pd[i]+d[i];
            int x = f(i);
            while(L <= R && f(dq[R]) >= x) 
                R--;
            dq[++R] = i;
        }
        cout << dp[n] << endl;
        if(T) cout << endl;
    }
    return 0;
}
