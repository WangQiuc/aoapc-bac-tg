// UVa 10340 All in All
// wangqc
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s, t;
    while(cin >> s >> t)
    {
        int i = 0, n = s.length(), m = t.length();
        for(int j = 0; i < n; i++, j++)
        {
            while(j < m && s[i] != t[j]) j++;
            if(j == m) break;
        }
        cout << (i == n ? "Yes" : "No") << endl;
    }
    return 0;
}
