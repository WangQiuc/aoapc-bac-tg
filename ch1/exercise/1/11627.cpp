// UVa 11627 Slalom
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 100005, maxs = 1000005;
const double eps = 1e-8;
int n, m;
double w, v, x[maxn], y[maxn], s[maxs];

bool valid(double k)
{   // [L, R] reachable range
    double L = x[0], R = x[0]+w, dx;
    for(int i = 1; i < n; i++)
    {
        dx = (y[i]-y[i-1]) * v / k;
        L = max(L-dx, x[i]);
        R = min(R+dx, x[i]+w);
        if(L-R > eps) return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> w >> v >> n;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> s[i];
        sort(s, s+m);
        int L = 0, R = m-1;
        while(L <= R)
        {
            int M = (L+R)>>1;
            if(valid(s[M])) L = M+1;
            else R = M-1;
        }
        if(R < 0) cout << "IMPOSSIBLE" << endl;
        else cout << (int)s[R] << endl;
    }
    return 0;
}
