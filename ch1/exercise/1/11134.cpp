// UVa 11134 Fabled Rooks
// wangqc
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 5005;

int n, x1[maxn], y1[maxn], x[maxn], y[maxn];

struct Node
{
    int v, i;
    Node(int v=0, int i=0):  v(v), i(i) {};
    bool operator < (const Node &rhs) const { return v > rhs.v; }
} x0[maxn], y0[maxn];

inline bool cmp (const Node &a, const Node &b) { return a.v < b.v; }

bool valid(Node *a0, int *a1, int *a)
{
    priority_queue<Node> pq;
    int i = 0, slot = 0;
    while(i < n)
    {
        while(pq.empty())
        {
            slot++;
            for(; i < n && a0[i].v == slot; i++)
                pq.push(Node(a1[a0[i].i], a0[i].i));
        }
        while(!pq.empty())
        {
            Node u = pq.top(); pq.pop();
            if(u.v < slot) return false;
            a[u.i] = slot++;
            for(; i < n && a0[i].v == slot; i++)
                pq.push(Node(a1[a0[i].i], a0[i].i));
        }
    }
    return true;
}

int main()
{
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> x0[i].v >> y0[i].v >> x1[i] >> y1[i];
            x0[i].i = y0[i].i = i;
        }
        sort(x0, x0+n, cmp);
        sort(y0, y0+n, cmp);
        if(valid(x0, x1, x) && valid(y0, y1, y))
            for(int i = 0; i < n; i++)
                cout << x[i] << " " << y[i] << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
