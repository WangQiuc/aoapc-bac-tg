// UVa 1368 DNA Consensus String
// wangqc
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const string TOKEN = "ACGT";
int ctr[1005][4];

int main()
{
    int T, n, m;
    string s;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        memset(ctr, 0, sizeof(ctr));
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            for(int j = 0; j < m; j++)
                ctr[j][TOKEN.find(s[j])]++;
        }
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            int j = 0;
            for(int k = 1; k < 4; k++) 
                if(ctr[i][j] < ctr[i][k]) j = k;
            cout << TOKEN[j];
            cnt += n-ctr[i][j];
        }
        cout << endl << cnt << endl;
    }
    return 0;
}
