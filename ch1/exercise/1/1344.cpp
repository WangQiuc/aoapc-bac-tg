// UVa 1344 Tian Ji -- The Horse Racing
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 1005, reward = 200;
int a[maxn], b[maxn];

int main()
{
    int n, cnt;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a+n);
        sort(b, b+n);
        int i0 = 0, i1 = n-1, j0 = 0, j1 = n-1, cnt = 0;
        while(i0 <= i1)
        {
            if(a[i1] > b[j1]) i1--, j1--, cnt++;
            else if(a[i1] == b[j1] && a[i0] > b[j0]) i0++, j0++, cnt++;
            else cnt -= (a[i0++] != b[j1--]);
        }
        cout << cnt * reward << endl;
    }
    return 0;
}
