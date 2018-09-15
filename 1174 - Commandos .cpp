#include<bits/stdc++.h>
using namespace std;
#define mx 101
vector<int > adj[mx];
int vis[mx];
int lev1[mx];
int lev2[mx];
void bfs(int s,int l)
{
    if(l==1)
        lev1[s] = 0;
    else
        lev2[s] = 0;
    vis[s] = 1;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        int sz = adj[u].size();
        for(int i=0; i<sz; i++){
            int v = adj[u][i];
            if(vis[v]==0){
                if(l==1)
                    lev1[v] = lev1[u]+1;
                else
                    lev2[v] = lev2[u]+1;
                vis[v] = 1;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int tc,u,v,n,r,s,d;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&r);
        for(int i=1; i<=r; i++){
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        scanf("%d%d",&s,&d);
        for(int i=0; i<=n; i++) vis[i] = 0;
        bfs(s,1);
        for(int i=0; i<=n; i++) vis[i] = 0;
        bfs(d,2);
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, lev1[i]+lev2[i]);

        printf("Case %d: %d\n",t,ans);
        for(int i=0; i<=n; i++)
            adj[i].clear();
    }
    return 0;
}
