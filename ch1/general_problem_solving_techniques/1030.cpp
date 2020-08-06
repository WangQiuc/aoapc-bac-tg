// UVa 1030 Image Is Everything
// wangqc
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 10;
int n;
char mat[maxn][maxn][maxn];
char view[6][maxn][maxn];

char read_char()
{
    char c;
    for(;;)
    {
        c = getchar();
        if((c >= 'A' && c <= 'Z') || c == '.') return c;
    }
}

void get_pos(int k, int i, int j, int d, int &x, int &y, int &z)
{
    if(k == 0) x = d, y = j, z = i;
    if(k == 1) x = n-1-j, y = d, z = i;
    if(k == 2) x = n-1-d, y = n-1-j, z = i;
    if(k == 3) x = j, y = n-1-d, z = i;
    if(k == 4) x = n-1-i, y = j, z = d;
    if(k == 5) x = i, y = j, z = n-1-d;
}

int main()
{
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            for(int k = 0; k < 6; k++)
                for(int j = 0; j < n; j++)
                    view[k][i][j] = read_char();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    mat[i][j][k] = '?';
        for(int k = 0; k < 6; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++) if(view[k][i][j] == '.')
                    for(int d = 0; d < n; d++)
                    {
                        int x, y, z;
                        get_pos(k, i, j, d, x, y, z);
                        mat[x][y][z] = '.';
                    }
        for(;;)
        {
            bool ok = true;
            for(int k = 0; k < 6; k++)
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++) if(view[k][i][j] != '.')
                    {
                        for(int d = 0; d < n; d++)
                        {
                            int x, y, z;
                            get_pos(k, i, j, d, x, y, z);
                            if(mat[x][y][z] == '.') continue;
                            if(mat[x][y][z] == '?')
                            {
                                mat[x][y][z] = view[k][i][j];
                                break;
                            }
                            if(mat[x][y][z] == view[k][i][j]) break;
                            mat[x][y][z] = '.';  // has to be empty to avoid color conflict
                            ok = false;
                        }
                    }
            if(ok) break;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++) 
                    if(mat[i][j][k] != '.') ans++;
        printf("Maximum weight: %d gram(s)\n", ans);
    }
    return 0;
}
