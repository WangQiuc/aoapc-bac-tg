// UVa 1339 Ancient Cipher
// wangqc
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int a[26], b[26];

int main()
{
    string s, t;
    while(cin >> s >> t)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < s.length(); i++)
        {
            a[s[i]-'A']++;
            b[t[i]-'A']++;
        }
        sort(a, a+26);
        sort(b, b+26);
        bool ok = true;
        for(int i = 0; ok && i < 26; i++)
            ok = (a[i] == b[i]);
        cout << (ok ? "YES" : "NO") << endl;
    } 
    return 0;
}
