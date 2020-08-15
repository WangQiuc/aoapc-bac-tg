// UVa 11210 Chinese Mahjong
// wangqc
#include<iostream>
#include<cstring>

using namespace std;

const char *tiles[] = {
    "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T", 
    "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", 
    "1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W", 
    "DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"
};

int hand[14], ctr[34];  // # of tile x left

int ID(char *s)
{
    for(int i = 0; i < 34; i++)
        if(strcmp(tiles[i], s) == 0) return i;
    return -1;
}

int dfs(int d)  
{

    if(d == 4) return true; // need 4 combinations (not count Eye) to win
    bool ok;
    for(int i = 0; i < 34; i++) 
        if(ctr[i] >= 3)
        {
            ctr[i] -= 3;
            ok = dfs(d+1);          // need to reset ctr before return
            ctr[i] += 3;
            if(ok) return true;
        }
    for(int i = 0; i < 25; i++)     // Wind and Dragon cannot be Chow
        if(i % 9 <= 6 && ctr[i] >= 1 && ctr[i+1] >= 1 && ctr[i+2] >= 1)
        {
            ctr[i]--, ctr[i+1]--, ctr[i+2]--;
            ok = dfs(d+1);
            ctr[i]++, ctr[i+1]++, ctr[i+2]++;
            if(ok) return true;
        }
    return false;
}

bool check()
{
    bool ok;
    for(int i = 0; i < 34; i++) 
        if(ctr[i] >= 2)     // Eye
        {
            ctr[i] -= 2;
            ok = dfs(0);
            ctr[i] += 2;
            if(ok) return true;
        }
    return false;
}

int main()
{
    int kase = 0;
    char s[100];
    while(cin >> s && s[0] != '0')
    {
        cout << "Case " << ++kase << ":";
        memset(ctr, 0, sizeof(ctr));
        ctr[ID(s)]++;
        for(int i = 0; i < 12; i++)
        {
            cin >> s;
            ctr[ID(s)]++;
        }
        bool ok = false;
        for(int i = 0; i < 34; i++) if(ctr[i] < 4)
        {
            ctr[i]++;
            if(check())
            {
                ok = true;
                cout << " " << tiles[i];
            }
            ctr[i]--;
        }
        if(!ok) cout << " Not ready";
        cout << endl;
    }
    return 0;
}
