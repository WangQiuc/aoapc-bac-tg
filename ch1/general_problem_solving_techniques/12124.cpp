// UVa 12124 Assemble
// wangqc
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int maxn = 1005, inf = 0x3f3f3f3f;
int n, b, cnt;
map<string, int> id;

int ID(string s)
{
    if(!id.count(s)) id[s] = cnt++;
    return id[s];
}

struct Node
{
    int p, q;
    bool operator < (const Node &rhs) const { return p < rhs.p; }
};

vector<Node> nodes[maxn];

// binary search check, whether quality >= q is within budget
bool ok(int q)
{
    int sum = 0;
    for(int i = 0; i < cnt; i++)
        for(auto x : nodes[i]) if(x.q >= q)
        {
            if((sum += x.p) > b) return false;
            break;
        }
    return true;

}

// binary search
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> b;
        cnt = 0;
        for(int i = 0; i < n; i++)
            nodes[i].clear();
        id.clear();

        int L = inf, R = inf;
        for(int i = 0; i < n; i++)
        {
            string type, name;
            int p, q;
            cin >> type >> name >> p >> q;
            L = min(L, q);
            nodes[ID(type)].push_back((Node){p, q});
        }
        for(int i = 0; i < cnt; i++)
        {
            int maxq = 0;
            for(auto x : nodes[i])
                maxq = max(maxq, x.q);
            R = min(R, maxq);
            sort(nodes[i].begin(), nodes[i].end());
        }
        while(L < R)
        {
            int M = L + ((R-L+1) >> 1);     // search large end
            if(ok(M)) L = M;
            else R = M-1;
        }
        cout << L << endl;
    }
    return 0;
}
