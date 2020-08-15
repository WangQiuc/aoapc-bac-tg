// UVa
// wangqc
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

const int maxn = 65;
int n, start[maxn], target[maxn];

// moves # to make [0,i] disks to peg j
ll f(int *P, int i, int j)  
{
    if(i == 0) return 0;
    if(P[i] == j) return f(P, i-1, j);
    // move i disks to another peg (neither P[i] nor j) costs 2^i-1 (Σ2^x) steps
    return f(P, i-1, 6-P[i]-j) + (1ll<<(i-1)); 
}

int main()
{
    int kase = 0;
    while(cin >> n && n)
    {
        for(int i = 1; i <= n; i++)
            cin >> start[i];
        for(int i = 1; i <= n; i++)
            cin >> target[i];
        int i = n;
        while(i >= 1 && start[i] == target[i])
            i--;
        long long ans = 0;
        if(i >= 1)
        {
            int j = 6 - start[i] - target[i];
            ans = f(start, i-1, j) + f(target, i-1, j) + 1;
        }
        cout << "Case " << ++kase << ": " << ans << endl;
    }
    return 0;
}
