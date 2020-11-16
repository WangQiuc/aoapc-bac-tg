// UVa 1316 Supermarket
// wangqc
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int maxn = 10005;
vector<int> a[maxn];

int main()
{
    int n, p, d, D, ans;
    while(cin >> n)
    {
        for(int i = 0; i < maxn; i++)
            a[i].clear();
        D = ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> p >> d;
            a[d].push_back(p);
            D = max(D, d);
        }
        priority_queue<int> pq;
        for(d = D; d > 0; d--)
        {
            for(int x : a[d])
                pq.push(x);
            if(pq.empty()) continue;
            ans += pq.top(); pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
