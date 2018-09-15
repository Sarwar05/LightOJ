#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define pii pair<int, int>
vector<int> adj[mx];
int vis[mx],low[mx],dis[mx],Time,touch;
pii makeBridge(int a, int b)
{
    return pii(min(a,b), max(a,b));
}
set<pii>bridge;
void dfs(int u, int par)
{
    vis[u] = 1;
    dis[u] = low[u] = ++Time;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==par) continue;
        if(vis[v]==1){
            low[u] = min(low[u], dis[v]);
        }
        else{
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if(dis[u]<low[v])
                bridge.insert(makeBridge(u,v));
        }
    }
}
void dfs(int u)
{
    vis[u] = 1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(bridge.count(makeBridge(u,v))){
            touch++;
            continue;
        }
        if(vis[v]) continue;
        dfs(v);
    }
}
int main()
{
    int tc,cs=1,n,m,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        bridge.clear();
        Time = 0;
        for(int i=0; i<n; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0,-1);
        int cc1 = 0;
        memset(vis, 0, sizeof vis);
        for(int i=0; i<n; i++){
            if(vis[i])continue;
            touch = 0;
            dfs(i);
            if(touch==1)
                cc1++;
        }
        cc1++;
        printf("Case %d: %d\n",cs++,cc1/2);
    }
}