// UVa 11078 Open Credit System
// wangqc
#include<iostream>

using namespace std;

const int inf = 1e7;

int main()
{
    int T; 
    cin >> T;
    while(T--)
    {
        int n, maxai, aj, ans = -inf;
        cin >> n >> maxai;
        for(int i = 1; i < n; i++)
        {
            cin >> aj;
            ans = max(ans, maxai-aj);
            maxai = max(maxai, aj);
        }
        cout << ans << endl;
    }
    return 0;
}
