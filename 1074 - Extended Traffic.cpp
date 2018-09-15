#include<bits/stdc++.h>
using namespace std;
#define N 202
#define inf 10000007
int arr[N];
struct Edge
{
    int u;int v;
    int cost;
    Edge(int _u,int _v, int _cost)
    {
        u = _u;
        v = _v;
        cost = _cost;
    }
};
vector<Edge>edge;
int dist[N], vis[N];
vector<int> adj[N];
void bfs(int s)
{
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<adj[x].size(); i++){
            int t = adj[x][i];
            if(vis[t]==0){
                vis[t] = 1;
                q.push(t);
            }
        }
    }
}
void bellman(int n, int e, int mx)
{
    for(int i=0; i<=N; i++) dist[i] = inf;
    dist[ 1]=0;
    for(int step = 1; step<=n+mx; step++){
        bool update = false;
        for(int i=0; i<edge.size(); i++){
            Edge x = edge[i];
            if(dist[x.u] + x.cost < dist[x.v]){
                update = true;
                dist[x.v] = dist[x.u]+x.cost;
            }
        }
        if(update == false)
            break;
    }
}

int main()
{
    int tc, cs=1, n,m,a,b,d,q;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
        scanf("%d",&m);
        int mx = 0;
        for(int i=1; i<=m; i++){
            scanf("%d%d",&a,&b);
            d = (arr[b]-arr[a]);
            d = d*d*d;
            mx = max(d, mx);
            adj[a].push_back(b);
            edge.push_back(Edge(a,b,d));
        }
        bfs(1);
        bellman(n,m, mx);
        scanf("%d",&q);
        printf("Case %d:\n", cs++);
        while(q--){
            scanf("%d",&a);
            if(dist[a]<3 || dist[a]==inf || vis[a]==0) printf("?\n");
            else printf("%d\n", dist[a]);
        }
        edge.clear();
        for(int i=1; i<=n; i++) adj[i].clear();
    }
    return 0;
}
