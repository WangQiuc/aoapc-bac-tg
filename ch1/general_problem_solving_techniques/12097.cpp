// UVa 12097 Pie
// wangqc
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const double pi = acos(-1.0), eps = 1e-7;
const int maxn = 10005;

int n, f;
double s[maxn];

int ok(double x)    // able to get more than f pies with size of x ?
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if((cnt += floor(s[i]/x)) >= f) return true;
    return false;
}

// binary search
int main()
{
    int T;
    cin >> T;
    while(T--)
    { 
        cin >> n >> f;
        f++;
        double maxs = -1.0;
        for(int i = 0; i < n; i++)
        {
            int r;
            cin >> r;
            s[i] = pi * r * r;
            maxs = max(maxs, s[i]);
        }
        double L = 0, R = maxs;
        while(R-L > eps)
        {
            double M = (L+R) / 2;
            if(ok(M)) L = M;
            else R = M;
        }
        printf("%.4lf\n", L);
    }
    return 0;
}
