#include<bits/stdc++.h>
using namespace std;
#define mx 501
struct Edge
{
    int v;
    int cost;
    Edge(int _v, int _cost)
    {
        v = _v;
        cost = _cost;
    }
};
int mat[mx][mx];
bool operator < (Edge a, Edge b)
{
    return a.cost > b.cost;
}
bool comp(Edge a, Edge b)
{
    return a.cost<b.cost;
}
int dist[mx];

vector<Edge> adj[mx];

void  dijkstra(int s,int n)
{
    priority_queue<Edge> PQ;

    int vis[n];

    for(int i=0; i<n; i++) dist[i] = 10000000, vis[i]=0;
    int ans = 10000000;
    dist[s] = 0;
    vis[s] = 1;
    PQ.push(Edge(s,0));

    while(!PQ.empty())
    {
        Edge x = PQ.top();

        PQ.pop();

        int sz = adj[x.v].size();

        for(int i=0; i<sz; i++)
        {
            Edge e  = adj[x.v][i];

            int c = dist[e.v] ;

            int kk=max(mat[ x.v ][ e.v ], dist[x.v] );

            if(kk<dist[e.v])
            {
                dist[e.v]=kk;
                if(vis[e.v] != 1)
                {
                    vis[e.v]=1;
//                    printf("%d to %d -> updated to %d to %d\n",x.v,e.v,c,dist[e.v]);
                    PQ.push(Edge(e.v, dist[e.v]));
                }
            }
//            if(e.v==t)
//                ans = min(ans,dist[t]);
        }
        vis[x.v]=0;
    }
    for(int i=0; i<n; i++){
        if(dist[i]==10000000)
        printf("Impossible\n");
        else
            printf("%d\n",dist[i]);
    }

}

int main()
{
    //freopen("out.txt","w",stdout);
    int tc,n,m,u,v,w,source;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat[i][j] = 10000000;
            }
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            mat[u][v] = min(w, mat[u][v]);
            mat[v][u] = min(w, mat[v][u]);
            adj[u].push_back(Edge(v,w));
            adj[v].push_back(Edge(u,w));
        }

        scanf("%d",&source);
        printf("Case %d:\n",t);
        dijkstra(source,n);
        for(int i=0; i<n; i++)
            adj[i].clear();
    }

    return 0;
}
/**

1

3 6
1 2 7335
2 0 13172
0 2 19049
0 1 15649
1 2 10364
1 2 23514
0

*/

