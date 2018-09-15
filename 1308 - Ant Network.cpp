#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define ll long long
#define pii pair<int, int>
vector<int> adj[mx];
int vis[mx], low[mx], dis[mx], Time;
int ap[mx],bcc;
void dfs(int u, int par)
{
    int child = 0;
    vis[u] = 1;
    dis[u] = low[u] = ++Time;
    for(int i=0; i<(int)adj[u].size(); i++){
        int v = adj[u][i];
        if(v==par) continue;
        if(vis[v]==1){
            if(dis[v]  < dis[u]){
                low[u] = min(low[u], dis[v]);
            }
        }
        else{
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if(dis[u]<=low[v] && u!=0)
                ap[u] = 1;
            child++;
        }
        if(child>1 && u==0)
            ap[u] = 1;
    }
}
int cnt,cuts;
void dfs2(int u)
{
    vis[u] = 1;
    cnt++;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(vis[v]==0 && ap[v]==0) dfs2(v);
        if(ap[v] && vis[v]!=bcc){
            cuts++;
            vis[v] = bcc;
        }
    }
}
int main()
{
    int n,m,a,b,tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++){
            adj[i].clear();
            vis[i] = 0;
            ap[i] = 0;
        }
        while(m--){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        Time = bcc = 0;
        dfs(0,-1);
        memset(vis,0, sizeof vis);
        int ans1 = 0;
        unsigned ll ans2=1;
        for(int i=0; i<n; i++){
            if(vis[i]==0 && ap[i]==0){
                cnt = cuts = 0;
                bcc++;
                dfs2(i);
                if(cuts==0) ans1++;
                else if(cuts<2){
                    ans1++;
                    ans2*=cnt;
                }
            }
        }
        if(ans1==1){
            ans1 = 2;
            ans2 = n;
            unsigned ll tem = ans2-1;
            if(ans2%2==0) ans2/=2;
            else tem/=2;
            ans2*=tem;
        }
        printf("Case %d: %d %llu\n",cs++,ans1,ans2);
    }
}
