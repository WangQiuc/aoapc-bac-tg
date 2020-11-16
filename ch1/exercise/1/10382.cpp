// UVa 10382 Watering Grass
// wangqc
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
const int maxn = 10005;
const double eps = 1e-7, inf = 1e12;
pair<double, double> a[maxn];

int main()
{
    int n;
    double l, w;
    while(cin >> n >> l >> w)
    {
        w = w*w / 4.0;
        double x, r;
        int m = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> r;
            if(r*r <= w) continue;
            double dx = sqrt(r*r-w);
            a[m++] = {x-dx, x+dx};
        }
        sort(a, a+m);
        int cnt = 0;
        double prev = -inf, curr = 0;
        for(int i = 0; i < m; i++)
        {
            if(a[i].first > curr+eps || curr > l-eps) break;
            if(a[i].first > prev+eps) cnt++, prev = curr;
            curr = max(curr, a[i].second);
        }
        cout << (curr > l-eps ? cnt : -1) << endl;
    }
    return 0;
}
