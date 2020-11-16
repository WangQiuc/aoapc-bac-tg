// UVa 11039 Building designing
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 500005;
int a[maxn], b[maxn];

int main()
{
    int T, n, x;
    cin >> T;
    while(T--)
    {
        cin >> n;
        int na = 0, nb = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(x > 0) a[na++] = x;
            else b[nb++] = -x;
        }
        sort(a, a+na);
        sort(b, b+nb);
        int i = 0, j = 0, cnt = 1;
        while (i < na && j < nb)
        {
            if(a[i] < b[j])
                while(i < na && a[i] < b[j]) i++;
            else
                while(j < nb && a[i] > b[j]) j++;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
