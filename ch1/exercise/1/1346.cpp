// UVa 1346 Songs
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

// Rank between i and j
// Diff f[i]*(C+l[i])+f[j]*(C+l[i]+l[j]) - (f[j]*(C+l[j])+f[i]*(C+l[i]+l[j]))
//   =  f[j]l[i] - f[i]l[j] = (k[i]-k[j])*l[i]l[j] where k[i] = l[i]/f[i]
// So rank by k

const int maxn = 1<<16;
pair<double, int> a[maxn];

int main()
{
    int n, id;
    double l, f;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> id >> l >> f;
            a[i] = {l/f, id};
        }
        sort(a, a+n);
        cin >> id;
        cout << a[id-1].second << endl;
    }
    return 0;
}
