// UVa 1335 Beijing Guards
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 100005;
int n, a[maxn], l[maxn], r[maxn];   // ith person get l[i] awards from [1,a1], r[i] awards from [a1+1,n]

// whether x awards are enough
bool ok(int x)
{
    int p = a[1], q = x - a[1];
    l[1] = p, r[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(i&1)
        {
            r[i] = min(a[i], q-r[i-1]);
            if((l[i] = a[i]-r[i]) > p) return false;
        }
        else
        {
            l[i] = min(a[i], p-l[i-1]);
            if((r[i] = a[i]-l[i]) > q) return false;
        }
    }
    return l[n] == 0;   // nth person cannot conflict with 1st person
}

int main()
{
    while(cin >> n && n)
    {
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        if(n == 1) 
        {   cout << a[1] << endl; continue; }
        a[n+1] = a[1];
        int L = 0, R = 0;
        for(int i = 1; i <= n; i++)
            L = max(L, a[i]+a[i+1]);
        if(n & 1)
        {
            for(int i = 1; i <= n; i++)
                R = max(R, a[i] * 3);
            while(L < R)
            {
                int M = (L + R) >> 1;
                if(ok(M)) R = M;
                else L = M + 1;
            }
        }
        cout << L << endl;
    }
    return 0;
}
