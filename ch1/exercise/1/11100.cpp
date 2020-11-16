// UVa 11100 The Trip, 2007
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 10005;

int a[maxn];

int main()
{
    int n, k, ctr, kase = 0;
    while(cin >> n && n)
    {
        if(kase++) cout << endl;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        k = ctr = 1;
        for(int i = 1; i < n; i++)
        {
            if(a[i] == a[i-1]) k = max(k, ++ctr);
            else ctr = 1;
        }
        cout << k << endl;
        for(int i = 0, j; i < k; i++)
        {
            for(j = i; j < n-k; j += k)
                cout << a[j] << " ";
            cout << a[j] << endl;
        }
    }
    return 0;
}
