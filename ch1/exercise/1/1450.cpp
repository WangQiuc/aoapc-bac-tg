// UVa 1450 Airport
// wangqc
#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 5005;
int n, a[maxn], b[maxn];

bool valid(int x)
{
    int sa = 0, sb = 0, k = 0;  // k buffer that ready to get off
    for(int i = 0; i < n; i++)
    {
        sa += a[i], sb += b[i];
        // fail if #planes have to get off > buffer
        if(max(0, sa-x) + max(0, sb-x) > k) 
            return false;
        if(!sa && sb) sb--;
        else if(!sb && sa) sa--;
        else if(sa && sb && sa + sb > k) k++;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        int L = 1, R = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            R += max(a[i], b[i]);
        }
        while(L < R)
        {
            int M = L + R >> 1;
            if(valid(M)) R = M;
            else L = M+1;
        }
        cout << L-1 << endl;

    }
    return 0;
}
