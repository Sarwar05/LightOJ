#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define mms(var, val) memset(var, val, sizeof var)
int vis[mx], par[mx], d[mx], low[mx], root, Time, ap[mx];
vector<int> adj[mx];
void refresh()
{
    for(int i=0; i<mx; i++){
        adj[i].clear();
    }
    mms(vis, 0);
    mms(par,-1);
    mms(d,0);
    mms(low, 0);
    mms(ap,0);
}
void DFS(int u)
{
    Time++;
    low[u] = d[u] = Time;
    vis[u] = 1;
    int child = 0;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(par[u]==v) continue;
        else if(vis[v]==1)
            low[u] = min(low[u], d[v]);
        else{
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if(d[u]<=low[v] && u!= root)
                ap[u] = 1;
            child++;
        }
        if(child>1 && u == root)
            ap[u] = 1;
    }
    Time++;
}
int main()
{
    int tc,cs=1, n,m,a,b;
    scanf("%d",&tc);
    while(tc--){
        refresh();
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        Time = 0;root = 1;
        DFS(root);
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(ap[i]==1)
                ans++;
        }
        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}
