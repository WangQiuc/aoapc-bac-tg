// UVa 11636 Hello World!
// wangqc
#include<iostream>

using namespace std;

int main()
{
    int n, kase = 0;
    while(cin >> n && n >= 0)
    {
        n--;
        int cnt = 0;
        while(n)
        {
            n >>= 1;
            cnt++;
        }
        cout << "Case " << ++kase << ": " << cnt << endl;
    }
    return 0;
}
