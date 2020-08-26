// UVa 11462 Age Sort
// wangqc
#include<cstdio>
#include<cstring>

const int maxn = 105;
int ctr[maxn];

int main()
{
    int n, x;
    while(scanf("%d", &n) == 1 && n)
    {
        memset(ctr, 0, sizeof(ctr));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            ctr[x]++;
        }
        bool first = true;
        for(int i = 0; i < maxn; i++)
            for(int j = 0; j < ctr[i]; j++)
            {
                if(first) first = false;
                else printf(" ");
                printf("%d", i);
            }
        printf("\n");
    }
    return 0;
}
