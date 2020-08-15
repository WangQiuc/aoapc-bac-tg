// UVa 1352 Colored Cubes
// wangqc
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// int left[] = {4, 0, 2, 3, 5, 1};
// int up[] = {2, 1, 5, 0, 4, 3};

// void rot(int *T, int *p)
// {
//     int q[6];
//     memcpy(q, p, sizeof(q));
//     for(int i = 0; i < 6; i++) p[i] = T[q[i]];
// }

// void gen_permutations()
// {
//     int p0[6] = {0, 1, 2, 3, 4, 5};
//     printf("const int rot[24][6] = {\n");
//     for(int i = 0; i < 6; i++)
//     {
//         int p[6];
//         memcpy(p, p0, sizeof(p0));
//         if(i == 0) rot(up, p);
//         if(i == 1) { rot(left, p); rot(up, p); }
//         if(i == 3) { rot(up, p); rot(up, p); }
//         if(i == 4) { rot(left, p); rot(left, p); rot(left, p); rot(up, p); }
//         if(i == 5) { rot(left, p); rot(left, p); rot(up, p); }
//         for(int j = 0; j < 4; j++)
//         {
//             printf("{%d, %d, %d, %d, %d, %d}, ", p[0], p[1], p[2], p[3], p[4], p[5]);
//             rot(left, p);
//         }
//         printf("\n");
//     }
//     printf("};\n");
// }
// 24 rotated variation
const int rot[24][6] = {
    {2, 1, 5, 0, 4, 3}, {2, 0, 1, 4, 5, 3}, {2, 4, 0, 5, 1, 3}, {2, 5, 4, 1, 0, 3},
    {4, 2, 5, 0, 3, 1}, {5, 2, 1, 4, 3, 0}, {1, 2, 0, 5, 3, 4}, {0, 2, 4, 1, 3, 5},
    {0, 1, 2, 3, 4, 5}, {4, 0, 2, 3, 5, 1}, {5, 4, 2, 3, 1, 0}, {1, 5, 2, 3, 0, 4},
    {5, 1, 3, 2, 4, 0}, {1, 0, 3, 2, 5, 4}, {0, 4, 3, 2, 1, 5}, {4, 5, 3, 2, 0, 1},
    {1, 3, 5, 0, 2, 4}, {0, 3, 1, 4, 2, 5}, {4, 3, 0, 5, 2, 1}, {5, 3, 4, 1, 2, 0},
    {3, 4, 5, 0, 1, 2}, {3, 5, 1, 4, 0, 2}, {3, 1, 0, 5, 4, 2}, {3, 0, 4, 1, 5, 2},
};
const int maxn = 4;
int n, dice[maxn][6], r[maxn], color[maxn][6], ans;
vector<string> names;

int ID(string s)
{
    int n = names.size();
    for(int i = 0; i < n; i++)
        if(names[i] == s) return i;
    names.push_back(s);
    return n;
}

void check()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 6; j++) 
            color[i][rot[r[i]][j]] = dice[i][j];
    int cnt = 0;
    for(int j = 0; j < 6; j++)
    {
        int ctr[maxn*6];
        memset(ctr, 0, sizeof(ctr));
        int max_face = 0;
        for(int i = 0; i < n; i++)
            max_face = max(max_face, ++ctr[color[i][j]]);
        cnt += n - max_face;    // number of faces that need to be repainted
    }
    ans = min(ans, cnt);
}

void permu(int d)
{
    if(d == n) check();
    else for(int i = 0; i < 24; i++)
    {
        r[d] = i;
        permu(d+1);
    }
}

int main()
{
    while(cin >> n && n)
    {
        names.clear();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 6; j++)
            {
                string s;
                cin >> s;
                dice[i][j] = ID(s);
            }
        ans = n*6;
        r[0] = 0;   // 1st cube not rotate
        permu(1);   // start permu from the 2nd cube
        cout << ans << endl;
    }
    return 0;
}
