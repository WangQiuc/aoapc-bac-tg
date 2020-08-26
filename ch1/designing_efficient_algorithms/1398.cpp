// UVa 1398 Meteor
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 100005;
const double inf = 1e9;

struct Event
{
    double x;
    bool in;    // true: enter the region, false: exit the region, sort out before in
    bool operator < (const Event &rhs) const { return x < rhs.x || (x == rhs.x && in < rhs.in); }
} events[maxn<<1];

// 0 < x+at < w
void get_interval(int x, int a, int w, double &L, double &R)
{
    if(a)
    {
        L = max(L, (a > 0 ? -(double)x/a : (double)(w-x)/a));
        R = min(R, (a > 0 ? (double)(w-x)/a : -(double)x/a));
    }
    else if(x <= 0 || x >= w) 
        R = L-1;
}

// sweep line
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int w, h, n, m = 0;
        cin >> w >> h >> n;
        for(int i = 0; i < n; i++)
        {
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            double L = 0, R = inf;
            get_interval(x, a, w, L, R);
            get_interval(y, b, h, L, R);
            if(L < R)
            {
                events[m++] = (Event){L, true};
                events[m++] = (Event){R, false};
            }
        }
        sort(events, events+m);
        int cnt = 0, max_cnt = 0;
        for(int i = 0; i < m; i++)
        {
            if(events[i].in) max_cnt = max(max_cnt, ++cnt);
            else cnt--;
        }
        cout << max_cnt << endl;
    }
    return 0;
}
