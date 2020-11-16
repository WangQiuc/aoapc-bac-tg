// UVa 10905 Children's Game
// wangqc
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int maxn = 55;
string s[maxn];

inline bool cmp(string a, string b) { return a+b > b+a; }

int main()
{
    int n;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
            cin >> s[i];
        sort(s, s+n, cmp);
        for(int i = 0; i < n; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}
