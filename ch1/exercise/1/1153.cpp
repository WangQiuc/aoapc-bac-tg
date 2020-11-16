// UVa 1153 Keep the Customer Satisfied
// wangqc
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 800005;
pair<int, int> nodes[maxn];

int main()
{
    int T, n, p, d;
    cin >> T;
    for(int kase = 0; kase < T; kase++)
    {
        cin >> n;
        for(int i = 0; i < n;)
        {
            cin >> p >> d;
            if(d >= p) nodes[i++] = {d, p};
            else n--;
        }
        sort(nodes, nodes+n);
        priority_queue<int> pq;
        int cnt = 0;
        for(int i = 0, t = 0; i < n; i++)
        {
            t += nodes[i].second;
            pq.push(nodes[i].second);
            if(nodes[i].first < t) { t -= pq.top(); pq.pop(); }
            else cnt++;
        }
        if(kase) cout << endl;
        cout << cnt << endl;
    }
    return 0;
}
