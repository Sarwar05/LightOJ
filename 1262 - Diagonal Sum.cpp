#include<bits/stdc++.h>
using namespace std;
#define ll int
#define inf 1e8
#define vi vector<int>
struct Edge
{
    int from;
    int to;
    ll cap;
    ll flow = 0;
    int a;
    Edge(int _from, int _to, ll _cap, int _a)
    {
        from = _from;
        to = _to;
        cap = _cap;
        a = _a;
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
    void addEdge(int from, int to, ll cap, int a)
    {
        edges.push_back(Edge(from, to, cap,a));
        adj[from].push_back(m++);
        edges.push_back(Edge(to, from, 0,-1));
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
#define mx 52
int mat[mx][mx], in, cross1[mx*mx], cross2[mx*mx], cnt1[mx*2], cnt2[mx*2];
int anti[mx*mx][2];
int main()
{
    int tc, cs=1, r,c;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d", &r,&c);
        int val = 0;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                mat[i][j] = ++val;
                anti[val][0] = i;
                anti[val][1] = j;
            }
        }
        int n = r+c-1;
        Dinic dinic(n + n + 2, 0, n + n + 1);
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
        int id = 1,x, p;
        memset(cross1, -1, sizeof cross1);
        for(int i=1,x=1; x<=r; i+=c, x++, id++){
            int now = i;
            p = i;
            while(now>0 && cross1[now]==-1){
                cross1[now] = id;
                cnt1[id]++;
                now-=(c-1);
            }
        }
        for(int i = p+1; i<=r*c; i++, id++){
            int now = i;
            while(now>0 && cross1[now]==-1){
                cross1[now] = id;
                cnt1[id]++;
                now-=(c-1);
            }
        }
        id = 1;
        memset(cross2, -1, sizeof cross2);
        for(int i=c,x=1; x<=r; i+=c, x++, id++){
            int now = i;
            p = i;
            while(now>0 && cross2[now]==-1){
                cross2[now] = id;
                cnt2[id]++;
                now-=(c+1);
            }
        }
        for(int i = p-1; cross2[i]==-1 && i>0; i--, id++){
            int now = i;
            while(now>0 && cross2[now]==-1){
                cross2[now] = id;
                cnt2[id]++;
                now-=(c+1);
            }
        }
        for(int i=1; i<=n; i++){
            scanf("%d", &in);
            dinic.addEdge(0, i, in - cnt1[i], -1);
        }
        for(int i=1; i<=n; i++){
            scanf("%d", &in);
            dinic.addEdge(n+i, n+n+1, in - cnt2[i], -1);
        }
        for(int i=1; i<=r*c; i++){
            dinic.addEdge(cross1[i], n+cross2[i], 99, i);
        }
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++)
                mat[i][j] = 1;
        }
        dinic.getFlow();
        for(int i=0; i<dinic.m; i++){
            int a = dinic.edges[i].a;
            if(a != -1)
                mat[anti[a][0]][anti[a][1]]+=dinic.edges[i].flow;
        }
        printf("Case %d:\n", cs++);
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                printf("%d", mat[i][j]);
                if(j==c) printf("\n");
                else printf(" ");
            }
        }
    }
}
