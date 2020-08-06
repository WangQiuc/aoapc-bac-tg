// UVa 11292 Dragon of Loowater
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 20005;
int a[maxn], b[maxn];

// sort and two pointer
int main()
{
    int n, m;
    while(cin >> n >> m && n)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];
        sort(a, a+n);
        sort(b, b+m);
        int i = 0, j = 0, cost = 0;
        for(; i < n; i++, j++)
        {
            while(j < m && a[i] > b[j]) j++;
            if(j == m) break;
            cost += b[j];
        }
        if(i == n) cout << cost << endl;
        else cout << "Loowater is doomed!" << endl;

    }
    return 0;
}
