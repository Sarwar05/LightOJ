#include<bits/stdc++.h>
using namespace std;
#define inf  1e9
#define vi vector<int>
/// https://vjudge.net/solution/10746811
/// 0 based
struct Edge
{
    int from;
    int to;
    int cap;
    int flow = 0;
    int cost;
    Edge(int _from, int _to, int _cap, int _cost)
    {
        from = _from;
        to = _to;
        cap = _cap;
        cost = _cost;
    }
};
struct MCMF
{
    vector<Edge> edges;
    vector<vi> adj;
    int n, m=0;
    int source,sink;
    vi dist,par, pass;
    queue<int> q;
    MCMF(int _n, int _source, int _sink)
    {
        n = _n;
        source = _source;
        sink = _sink;
        adj.resize(n);
        par.resize(n);
        dist.resize(n);
        pass.resize(n);
    }
    void addEdge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge(from, to, cap, cost));
        adj[from].push_back(m++);
        edges.push_back(Edge(to, from, 0, -cost));
        adj[to].push_back(m++);
    }
    bool spfa()
    {
        fill(dist.begin(), dist.end(), inf);
        vector<bool> inq(n, false);
        par[source] = 0;
        pass[source] = inf;
        dist[source] = 0;
        q.push(source);
        inq[source] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            inq[u] = false;
            for(int i=0; i<adj[u].size(); i++){
                int id = adj[u][i];
                int v = edges[id].to;
                int cap  = edges[id].cap;
                int flow = edges[id].flow;
                int cost = edges[id].cost;
                if(cap>flow && dist[v] > dist[u]+cost){
                    dist[v] = dist[u]+cost;
                    par[v] = id;
                    pass[v] = min(pass[u], cap-flow);
                    if(inq[v]==false){
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return dist[sink]!=inf;
    }
    int mincost_maxflow()
    {
        int flow = 0, cost = 0;
        while(spfa()){
            flow+=pass[sink];
            cost+=dist[sink];
            int now =  sink;
            while(now!=source)
            {
                int id = par[now];
                edges[ id ].flow+=pass[sink];
                edges[id^1].flow-=pass[sink];
                now = edges[id].from;
            }
        }
        return cost;
    }
};
#define mx 102
int mat[mx][mx], idx[mx][mx];
int main()
{
    int tc, cs=1, n, m;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d%d", &n,&m);
        int val = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d", &mat[i][j]);
                idx[i][j] = val++;
            }
        }
        MCMF mcmf(n*m*2, 0, n*m*2-1);
        /// split node
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if((i==1 && j==1) || (i==n && j==m))
                    mcmf.addEdge(idx[i][j], (n*m) + idx[i][j], 2, -mat[i][j]);
                else mcmf.addEdge(idx[i][j], (n*m) + idx[i][j], 1, -mat[i][j]);
            }
        }
        /// connect to right & down
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(i<n)
                    mcmf.addEdge(n*m + idx[i][j], idx[i+1][j], 1, 0);
                if(j<m)
                    mcmf.addEdge(n*m + idx[i][j], idx[i][j+1], 1, 0);
            }
        }
        printf("Case %d: %d\n",cs++, -mcmf.mincost_maxflow() - mat[1][1] - mat[n][m]);
    }
}
