// UVa 1121 Subsequence
// wangqc
#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 100005;
int B[maxn];  // prefix sum array

int main()
{
    int n, s;
    B[0] = 0;
    while(cin >> n >> s)
    {
        int x, i = 1, ans = n+1;
        for(int j = 1; j <= n; j++)
        {
            cin >> x;
            B[j] = B[j-1] + x;
            if(B[j] - B[i-1] < s) continue;     // do not update ans
            while(B[j] - B[i] >= s) i++;
            ans = min(ans, j-i+1);
        }
        cout << (ans == n+1 ? 0 : ans) << endl;
    }
    return 0;
}
