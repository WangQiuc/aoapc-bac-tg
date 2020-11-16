// UVa 1422 Processor
// wangqc
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
const int maxn = 10005, maxr = 20000;
int n, D, L, R;

struct Node
{
    int r, d, w;
    bool operator < (const Node &rhs) const { return d > rhs.d; }
} nodes[maxn];

inline bool cmp(const Node &a, const Node &b) { return a.r < b.r; }

// whether speed s is valid
bool valid(int s)
{
    priority_queue<Node> pq;
    int i = 0;
    for(int t = 1; t <= D; t++)
    {
        while(i < n && nodes[i].r == t)
            pq.push(nodes[i++]);  // works start at t are ready to be processed
        int k = s;
        while(k && !pq.empty())
        {
            Node x = pq.top(); pq.pop();
            if(x.d == t) return false;   // work x cannot be finished by x.d
            if(x.w > k)     // process amount of k for work x
            {
                x.w -= k;
                k = 0;
                pq.push(x);
            }
            else k -= x.w;  // or finish work x
        }
        if(i == n && pq.empty())
            break;
    }
    return i == n && pq.empty();    // all works are finished or not
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        L = 1, R = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> nodes[i].r >> nodes[i].d >> nodes[i].w;
            D = max(D, nodes[i].d);
            R += nodes[i].w;
        }
        sort(nodes, nodes+n, cmp);
        while(L < R)
        {
            int M = (L+R)>>1;
            if(valid(M)) R = M;
            else L = M+1;
        }
        cout << L << endl;
    }
    return 0;
}
