// UVa 10755 Garbage Heap
// wangqc
#include<iostream>
#include<cstring>

using namespace std;
typedef long long ll;

const int maxn = 30;
const ll inf = 1ll << 60;
ll S[maxn][maxn][maxn];

// 3D Prefix sum matrix 
// S(x,y,z) = S(x-1,y,z)+S(x,y-1,z)+S(x,y,z-1)-S(x-1,y-1,z)-S(x-1,y,z-1)-S(x,y-1,z-1)+S(x-1,y-1,z-1)+A(x,y)
// iterate(1,0,0),(0,1,0),(0,0,1),-(1,1,0),-(1,0,1),-(0,1,1),(1,1,1)
void get_d(int i, int &dx, int &dy, int &dz)
{
    dx = i & 1;
    i >>= 1;
    dy = i & 1;
    i >>= 1;
    dz = i;
}

int get_sign(int dx, int dy, int dz)
{
    return (dx + dy + dz) & 1 ? 1 : -1;
}

// 3D subsum between S(x1,y1,z1) and S(x2,y2,z2) =
// S(x2,y2,z2)-S(x1,y2,z2)-S(x2,y1,z2)-S(x2,y2,z1)+S(x1,y1,z2)+S(x1,y2,z1)+S(x1,y1,z2)-S(x1,y1,z1)
ll get_sum(int x1, int x2, int y1, int y2, int z1, int z2)
{
    int x = x2-x1+1, y = y2-y1+1, z = z2-z1+1;
    ll s = 0;
    for(int i = 0; i < 8; i++)
    {
        int dx, dy, dz;
        get_d(i, dx, dy, dz);
        s -= S[x2-x*dx][y2-y*dy][z2-z*dz] * get_sign(dx, dy, dz);
    }
    return s;
}


// 3D Maximal submatrix
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a, b, c, dx, dy, dz;
        cin >> a >> b >> c;
        memset(S, 0, sizeof(S));
        for(int x = 1; x <= a; x++)
            for(int y = 1; y <= b; y++)
                for(int z = 1; z <= c; z++)
                    cin >> S[x][y][z];
        for(int x = 1; x <= a; x++)
            for(int y = 1; y <= b; y++)
                for(int z = 1; z <= c; z++)
                    for(int i = 1; i < 8; i++)
                    {
                        get_d(i, dx, dy, dz);
                        S[x][y][z] += S[x-dx][y-dy][z-dz] * get_sign(dx, dy, dz);
                    }
        ll ans = -inf;
        for(int x1 = 1; x1 <= a; x1++)
            for(int x2 = x1; x2 <= a; x2++)
                for(int y1 = 1; y1 <= b; y1++)
                    for(int y2 = y1; y2 <= b; y2++)
                    {
                        ll M = 0;
                        for(int z = 1; z <= c; z++)
                        {
                            ll s = get_sum(x1, x2, y1, y2, 1, z);
                            ans = max(ans, s - M);
                            M = min(M, s);
                        }
                    }
        cout << ans << endl;
        if(T) cout << endl;
    }
    return 0;
}
