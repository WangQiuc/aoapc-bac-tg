// UVa 1418 WonderTeam
// wangqc
#include<iostream>

using namespace std;

// Lowest rank case:
//          W        L       P
//  1       2       n-1     n-3   --> wonder team, loss to all other teams once, win 2,3 once, 
//  2       1        1     2n-1
//  3       1        1     2n-1
// ...      1        0      2n

int main()
{
    int n;
    while(cin >> n && n)
    {
        if(n <= 4) cout << 1+(n>>2) << endl;
        else cout << n << endl;
    }
    return 0;
}
