// UVa 1330 City Game
// wangqc
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;
const int maxn = 1005;

int h[maxn];

int main()
{
    int T, m, n;
    char c;
    cin >> T;
    while(T--)
    {
        int ans = 0;
        cin >> m >> n;
        memset(h, 0, sizeof(h));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> c;
                h[j] = (c == 'F' ? h[j] + 1 : 0);
            }
            stack<int> s;
            s.push(-1);
            for(int j = 0; j <= n; j++)
            {
                while(s.size() > 1 && h[s.top()] > h[j])
                {
                    int k = s.top(); s.pop();
                    ans = max(ans, h[k]*(j-s.top()-1));
                }
                s.push(j);
            }
        }
        cout << ans * 3 << endl;
    }
    return 0;
}
