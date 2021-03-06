/**
Key: Bicoloring
*/




#include<bits/stdc++.h>
using namespace std;
#define mx 102
vector<int> adj[mx];
int  vis[mx];
int color[mx];
int par[mx];
int in;
int diff;
bool odd;

void bicolor(int s, int col)
{
    if(col%2==1) diff++;
    for(int i=0; i<adj[s].size(); i++){
        int u = adj[s][i];
        if(vis[u]==0){
            in++;
            par[u] = s;
            vis[u] = 1;
            color[u] = col+1;
            bicolor(u, col+1);
        }
        else if(par[u]!= s){
            if(color[u]%2 == col%2)
                odd = true;
        }
    }
}
int main()
{
    int tc,n,m,a,b,ans; scanf("%d",&tc);
    for(int t=1; t<=tc ;t++){
        memset(vis, 0, sizeof vis);
        memset(color, -1, sizeof color);
        memset(par, -1, sizeof par);
        scanf("%d%d",&n, &m);
        for(int i=1; i<=m; i++){
            scanf("%d%d",&a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        in= 1, diff=0;odd = false;
        vis[1] = 1;
        color[1] = 1;
        bicolor(1,1);
        ans = odd ? in : diff;
        if(adj[1].size()==0) ans = 0;
        printf("Case %d: %d\n",t,ans);
        if(t != tc){
            for(int i=1; i<=n; i++){
                adj[i].clear();
            }
        }
    }
}

