// UVa 1388 Graveyard
// wangqc
#include<stdio.h>
#include<math.h>

// greedy
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) == 2)
    {
        m += n;
        double ans = 0.0;
        for(int i = 1; i < n; i++)
        {   // make sure p >= 1, and after insertion, d is normalized to 1 
            double p = double(i)/n * m;         
            ans += fabs(p - floor(p+0.5)) / m;
        }
        printf("%.4lf\n", ans * 10000);
    }
    return 0;
}
