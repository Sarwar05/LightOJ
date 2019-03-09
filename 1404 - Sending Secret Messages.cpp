#include<bits/stdc++.h>
using namespace std;
#define inf  1e8
#define vi vector<int>
#define ll int
struct Edge
{
    int from;
    int to;
    ll cap;
    ll flow = 0;
    ll cost;
    Edge(int _from, int _to, ll _cap, ll _cost)
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
    vector<ll> dist, pass;
    vi par;
    queue<int> q;
    MCMF(int _n, int _source, int _sink)
    {
        n = _n+5;
        source = _source;
        sink = _sink;
        adj.resize(n);
        par.resize(n);
        dist.resize(n);
        pass.resize(n);
    }
    void addEdge(int from, int to, ll cap, ll cost)
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
                ll cap  = edges[id].cap;
                ll flow = edges[id].flow;
                ll cost = edges[id].cost;
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
    int mincost_maxflow(int lim)
    {
        ll flow = 0, cost = 0;
        while(spfa() && flow<lim){
            int need = lim - flow;
            flow+=pass[sink];
            cost+=(dist[sink]*min(need, pass[sink]));
            int now =  sink;
            while(now!=source)
            {
                int id = par[now];
                edges[ id ].flow+=pass[sink];
                edges[id^1].flow-=pass[sink];
                now = edges[id].from;
            }
        }
        return flow>=lim ? cost : -1;
    }
};

int main()
{
    int tc, cs=1;
    scanf("%d", &tc);
    while(tc--)
    {
        int n,m,a,b,c,d,p;
        scanf("%d%d%d", &n,&m,&p);
        MCMF mcmf(n+2, 1, n);
        while(m--){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            mcmf.addEdge(a,b,c,d);
            mcmf.addEdge(b,a,c,d);
        }
        printf("Case %d: ", cs++);
        int ans = mcmf.mincost_maxflow(p);
        if(ans==-1) printf("impossible\n");
        else printf("%d\n", ans);
    }
}
