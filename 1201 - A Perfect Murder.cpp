#include<bits/stdc++.h>
using namespace std;
#define mx 1002
vector<int> adj[mx];
int vis[mx];
int dp[mx][2];
int fun(int node,int par, int cnt)
{
    vis[node]=1;
    if(adj[node].size()==0) return 0;
    if(dp[node][cnt]!=-1) return dp[node][cnt];;
    int ret = 0;
    for(int i=0; i<adj[node].size(); i++){
        int v = adj[node][i];
        if(v==par) continue;
        if(cnt==0){
            ret+=fun(v,node,1);
        }
        else{
            ret+=min(fun(v,node,1),fun(v,node,0));
        }
    }
    return dp[node][cnt] = ret+cnt;
}
int main()
{
    int a,b,tc,cs=1,n,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) adj[i].clear();
        memset(vis,0,sizeof vis);
        memset(dp,-1,sizeof dp);
        for(int i=1; i<=m; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                ans+=min(fun(i,-1,0), fun(i,-1,1));
            }
        }
        printf("Case %d: %d\n",cs++,n-ans);
    }
}
