// UVa 11549 Calculator Conundrum
// wangqc
#include<iostream>
#include<cstring>

using namespace std;
typedef long long ll;

int buf[100];
int next(int n, int k)
{
    if(!k) return 0;
    ll k2 = (ll)k * k;
    int L = 0;
    while(k2)
    {
        buf[L++] = k2 % 10;
        k2 /= 10;
    }
    if(n > L) n = L;
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = ans * 10 + buf[--L];
    return ans;
}

int main()
{
    int n, k, T;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        int ans = k;
        int k1 = k, k2 = k;
        do
        {
            k1 = next(n, k1);
            ans = max(ans, k2=next(n, k2));
            ans = max(ans, k2=next(n, k2));
        } while (k1 != k2);
        cout << ans << endl;
    }
    return 0;
}
