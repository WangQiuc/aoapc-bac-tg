// UVa 11384 Help is needed for Dexter
// wangqc
#include<iostream>
#include<cstring>

using namespace std;

// f(n) = f(n/2) + 1: [n/2+1, n] -= n/2+1 -> [0, n/2-1] which covered by [1, n/2]
int f(int x) { return x == 1 ? 1 : f(x>>1) + 1; }

int main()
{
    int n;
    while(cin >> n)
        cout << f(n) << endl;
    return 0;
}
