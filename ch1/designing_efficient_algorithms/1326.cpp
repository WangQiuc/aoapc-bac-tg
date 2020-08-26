// UVa 1326 Jurassic Remains
// wangqc
#include<iostream>
#include<map>

using namespace std;

const int maxn = 24;
map<int, int> state;

int bit_count(int x)
{
    return x ? bit_count(x>>1) + (x&1) : 0;
}

// Meet in the middle, O(2^(n/2) * logn)
int main()
{
    int n, A[maxn];
    char s[50];
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            A[i] = 0;
            for(int j = 0; s[j] != '\0'; j++)
                A[i] ^= 1 << (s[j]-'A');
        }
        state.clear();
        int n1 = n>>1, n2 = n-n1;
        for(int i = 0; i < (1<<n1); i++)
        {
            int x = 0;
            for(int j = 0; j < n1; j++) if(i & (1<<j)) 
                x ^= A[j];
            if(!state.count(x) || bit_count(state[x]) < bit_count(i))
                state[x] = i;
        }
        int ans = 0;
        for(int i = 0; i < (1<<n2); i++)
        {
            int x = 0;
            for(int j = 0; j < n2; j++) if(i & (1<<j))
                x ^= A[n1+j];
            if(state.count(x) && bit_count(ans) < bit_count(state[x])+bit_count(i))
                ans = (i<<n1) | state[x];   // merge first and second half
        }
        cout << bit_count(ans) << endl;
        bool first = true;
        for(int i = 0; i < n; i++) if(ans & (1<<i))
        {
            if(first) { cout << i+1; first = false; }
            else cout << " " << i+1;
        }
        cout << endl;
    } 
    
    return 0;
}
