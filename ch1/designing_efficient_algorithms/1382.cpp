// UVa 1382 Distant Galaxy
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 105;

struct Point
{
    int x, y;
    bool operator < (const Point &rhs) const { return x < rhs.x; }
} P[maxn];

// on: exclusive, on2: inclusive, L: prefix sum array
int n, m, y[maxn], on[maxn], on2[maxn], L[maxn];

// 2d prefix sum
int solve()
{
    sort(P, P+n);
    sort(y, y+n);
    m = unique(y, y+n) - y;
    if(m <= 2) return n;
    int ans = 0;
    for(int a = 0; a < m; a++)
        for(int b = a+1; b < m; b++)
        {
            int miny= y[a], maxy = y[b];
            int j = 0;
            for(int i = 0; i < n; i++)
            {
                if(i == 0 || P[i].x != P[i-1].x)
                {
                    j++;
                    on[j] = on2[j] = 0;
                    L[j] = j ? L[j-1] + on2[j-1] - on[j-1] : 0;
                }
                if(P[i].y > miny && P[i].y < maxy) on[j]++;
                if(P[i].y >= miny && P[i].y <= maxy) on2[j]++;
            }
            if(j <= 2) return n;
            int curr = 0;
            for(int k = 1; k <= j; k++)
            {
                ans = max(ans, curr + L[k] + on2[k]);
                curr = max(curr, on[k] - L[k]);
            }
        }
    return ans;
}

int main()
{
    int kase = 0;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> P[i].x >> P[i].y;
            y[i] = P[i].y;
        }
        cout << "Case " << ++kase << ": " << solve() << endl;
    }
    return 0;
}
