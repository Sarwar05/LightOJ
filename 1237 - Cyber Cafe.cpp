#include<bits/stdc++.h>
using namespace std;
#define inf  1e8
#define vi vector<int>
#define ll int
#define pii pair<int, int>
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
    pii mincost_maxflow()
    {
        ll flow = 0, cost = 0;
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
        return make_pair(flow, cost);
    }
    void rev()
    {
        for(int i=0; i<m; i++){
            edges[i].flow = 0;
            edges[i].cost = -edges[i].cost;
        }
    }
};
int mp1[1002], mp2[1002];
int main()
{
    int tc, cs=1;
    scanf("%d", &tc);
    while(tc--)
    {
        int n,K,G;
        scanf("%d%d%d",&n,&K,&G);
        vector<int> enter(n+1), exit(n+1);
        set<int> st;

        for(int i=1; i<=n; i++){
            scanf("%d",&enter[i]);
            st.insert(enter[i]);
        }
        int val = 1;
        for(auto it = st.begin(); it!=st.end(); it++)
            mp1[ *it ] = val++;
        st.clear();

        for(int i=1; i<=n; i++){
            scanf("%d",&exit[i]);
            st.insert(exit[i]);
        }
        for(auto it = st.begin(); it!=st.end(); it++)
            mp2[ *it ] = val++;

        MCMF mcmf(val+1, 0, val);

        for(int i=1; i<=n; i++){
            mcmf.addEdge(0, mp1[ enter[i] ], 1, 0);
            mcmf.addEdge(mp2[ exit[i] ], val,1, 0);
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(enter[i]>=exit[j]) continue;
                int cst = exit[j] - enter[i];
                cst-=K;
                cst*=cst;
                cst = min(cst, G);
                mcmf.addEdge(mp1[enter[i]], mp2[exit[j]], 1, cst);
            }
        }
        pii ans1 = mcmf.mincost_maxflow();
        mcmf.rev();
        pii ans2 = mcmf.mincost_maxflow();
        printf("Case %d: ", cs++);
        if(ans1.first <n || ans2.first<n) printf("impossible\n");
        else printf("%d %d\n", ans1.second, -ans2.second);
    }
}

