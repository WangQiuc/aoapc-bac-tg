// UVa10881 Piotr's Ants
// wangqc
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 10005;
const char dirs[][10] = {"L", "Turning", "R"}; // d: {-1, 0, 1}
struct Ant
{
    int i, p, d;
    bool operator < (const Ant &rhs) const { return p < rhs.p; }
} pre[maxn], cur[maxn];

int seq[maxn]; // seq[i] is sorted position for ith input

// two ants hit and change direction == two ants pass cross each other
// each ant's order is never change, ith ant is bound within i-1th and i+1th ants and always stay at ith position
int main()
{
    int T, L, t, n;
    cin >> T;
    for(int kase = 1; kase <= T; kase++)
    {
        cin >> L >> t >> n;
        for(int i = 0; i < n; i++)
        {
            int p, d;
            char c;
            cin >> p >> c;
            d = (c == 'L' ? -1 : 1);
            pre[i] = (Ant) {i, p, d};
            cur[i] = (Ant) {0, p+t*d, d};   // i is not set
        }
        sort(pre, pre+n);
        for(int i = 0; i < n; i++)
            seq[pre[i].i] = i;
        sort(cur, cur+n);
        for(int i = 0; i < n-1; i++) if(cur[i].p == cur[i+1].p) 
            cur[i].d = cur[i+1].d = 0, i++;
        cout << "Case #" << kase << ":\n"; 
        for(int i = 0; i < n; i++)
        {
            int p = cur[seq[i]].p;
            if(p < 0 || p > L) cout << "Fell off" << endl;
            else cout << p << " " << dirs[cur[seq[i]].d+1] << endl;
        }
        cout << endl;
    }
    return 0;
}
