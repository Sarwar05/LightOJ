#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define vi vector<int>
/// https://en.wikipedia.org/wiki/Max-flow_min-cut_theorem#Application
struct Edge
{
    int from;
    int to;
    ll cap;
    ll flow=0;
    Edge(int _from, int _to, ll _cap)
    {
        from = _from;
        to = _to;
        cap = _cap;
    }
};
struct Dinic
{
    vector<Edge> edges;
    vector<vi> adj;
    int n, m=0;
    int source,sink;
    vi level, ptr;
    queue<int> q;
    Dinic(int _n, int _source, int _sink)
    {
        n = _n+5;
        source = _source;
        sink = _sink;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void addEdge(int from, int to, ll cap)
    {
        edges.push_back(Edge(from, to, cap));
        adj[from].push_back(m++);
        edges.push_back(Edge(to, from, 0));
        adj[to].push_back(m++);
    }
    bool bfs()
    {
        while(!q.empty()){
            int from = q.front();
            q.pop();
            for(int i=0; i<adj[from].size(); i++){
                int id = adj[from][i];
                int to = edges[id].to;
                if(edges[id].cap - edges[id].flow ==0)
                    continue;
                if(level[ to ] != -1) continue;
                level[to] = level[from] + 1;
                q.push(to);
            }
        }
        return level[sink] != -1;
    }
    ll dfs(int from, ll pushed)
    {
        if(pushed==0) return 0;
        if(from==sink) return pushed;
        for(int& cid = ptr[from]; cid<(int)adj[from].size(); cid++){
            int id = adj[from][cid];
            int to = edges[id].to;
            if(level[from]+1 != level[to] || edges[id].cap - edges[id].flow == 0)
                continue;
            ll tempFlow = dfs(to, min(pushed, edges[id].cap - edges[id].flow));
            if(tempFlow==0) continue;
            edges[id].flow +=tempFlow;
            edges[id^1].flow -=tempFlow;
            return tempFlow;
        }
        return 0;
    }
    ll getFlow()
    {
        //for(int i=0; i<m; i++) edges[i].flow = 0;
        ll maxFlow = 0;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[source] = 0;
            while(!q.empty()) q.pop();
            q.push(source);
            if(bfs()==false) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(source, inf))
                maxFlow+=pushed;
        }
        return maxFlow;
    }
};

int main()
{
    int tc, cs=1;
    scanf("%d", &tc);
    while(tc--)
    {
        int m,n,a,x;
        scanf("%d%d", &m,&n);
        int src = 0, snk = n + (2*m) + 2;
        Dinic dinic(n+m*2, src, snk);
        int ans = 0;
        for(int i=1; i<=m; i++){
            scanf("%d", &a);
            dinic.addEdge(src,i,a);
            ans+=a;
        }
        for(int i=1; i<=n; i++){
            scanf("%d", &a);
            dinic.addEdge(m+i, snk,a);
        }
        for(int i=1; i<=m; i++){
            scanf("%d", &x);
            while(x--){
                scanf("%d", &a);
                dinic.addEdge(i, m+a, inf);
            }
        }
        printf("Case %d: %d\n", cs++, ans - (int)dinic.getFlow());
    }
}
