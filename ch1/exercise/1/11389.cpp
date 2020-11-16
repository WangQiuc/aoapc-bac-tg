// UVa 11389 The Bus Driver Problem
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 10005;
int a[maxn], b[maxn];

int main()
{
    int n, d, r;
    while(cin >> n >> d >> r && n)
    {
        for(int i = 0; i < n; i++)  cin >> a[i];
        for(int i = 0; i < n; i++)  cin >> b[i];
        sort(a, a+n);
        sort(b, b+n, greater<int>());
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += max(0, a[i]+b[i]-d);
        cout << cnt * r << endl;
    }
    return 0;
}
