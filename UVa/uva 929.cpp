#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1000;
const int INF = 100000000;
int g[N][N], cost[N][N];
int T, r, c;
struct node
{
    int i, j, w;
    bool operator < ( const struct node a ) const
    {
        return w > a.w;
    }
} tl;
void dij()
{
    int mi, ri, ci;
    bool vis[N][N];
    priority_queue <node> pq;
    memset(vis, 0, sizeof(vis));
    g[1][1] = cost[1][1];
    tl.i = tl.j = 1, tl.w = g[1][1];
    pq.push(tl);
    while ( !pq.empty() )
    {
        tl = pq.top();
        pq.pop();
        ri = tl.i, ci = tl.j;
        if ( vis[ri][ci] ) continue;
        vis[ri][ci] = true;
        printf("%d  %d\n", ri, ci);
        if ( ri > 1 && !vis[ri-1][ci] && g[ri-1][ci] > g[ri][ci] + cost[ri-1][ci] )
        {
            g[ri-1][ci] = g[ri][ci] + cost[ri-1][ci];
            tl.i = ri-1, tl.j = ci, tl.w = g[ri-1][ci];
            pq.push(tl);
        }
        if ( ri < r && !vis[ri+1][ci] && g[ri+1][ci] > g[ri][ci] + cost[ri+1][ci] )
        {
            g[ri+1][ci] = g[ri][ci] + cost[ri+1][ci];
            tl.i = ri+1, tl.j = ci, tl.w = g[ri+1][ci];
            pq.push(tl);
        }
        if ( ci > 1 && !vis[ri][ci-1] && g[ri][ci-1] > g[ri][ci] + cost[ri][ci-1] )
        {
            g[ri][ci-1] = g[ri][ci] + cost[ri][ci-1];
            tl.i = ri, tl.j = ci-1, tl.w = g[ri][ci-1];
            pq.push(tl);
        }
        if ( ci < c && !vis[ri][ci+1] && g[ri][ci+1] > g[ri][ci] + cost[ri][ci+1] )
        {
            g[ri][ci+1] = g[ri][ci] + cost[ri][ci+1];
            tl.i = ri, tl.j = ci+1, tl.w = g[ri][ci+1];
            pq.push(tl);
        }
    }
}
int main()
{
    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d%d", &r, &c);
        for ( int i = 1; i <= r; ++i )
            for ( int j = 1; j <= c; ++j ) scanf("%d", &cost[i][j]), g[i][j] = INF;
        dij();
        printf("%d\n", g[r][c]);
    }
}
