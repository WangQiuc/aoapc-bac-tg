// UVa 1467 Installations
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 505;
int n, t[maxn];
pair<int, int> seq[maxn];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> seq[i].second >> seq[i].first;
        sort(seq, seq+n);
        int a = 0, b = 0, x = 0, p1 = 0, p2 = 0;
        t[0] = seq[0].second;
        for(int i = 1; i < n; i++) 
            t[i] = t[i-1] + seq[i].second;
        for(int i = 0; i < n; i++)
        {
            x = t[i]-seq[i].first;
            if(x >= a) b = a, a = x, p2 = p1, p1 = i;
            else if(x > b) b = x, p2 = i;
        }
        if(p2 < p1) swap(p1, p2);
        int s = t[p2], ans = a+b;
        for(int i = 0; i <= p1; i++)
        {
            a = b = 0;
            for(int j = 0; j < n; j++)
            {
                if(j < i) x = t[j];
                else if(j == i) x = s;
                else if(j <= p2) x = t[j]-seq[i].second;
                else x = t[j];
                x = max(0, x-seq[j].first);
                if(x >= a) b = a, a = x;
                else if(x > b) b = x;
            }
            ans = min(ans, a+b);
        }
        cout << ans << endl;
    }
    return 0;
}
