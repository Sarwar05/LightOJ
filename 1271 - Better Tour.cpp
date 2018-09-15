#include<bits/stdc++.h>
using namespace std;
#define mx 50005
vector<int> adj[mx];
int vis[mx], par[mx];
void bfs(int s, int t)
{
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(vis[v]==0){
                vis[v] = 1;
                par[v] = u;
                q.push(v);
                if(v==t) return;
            }
        }
    }
}
void printPath(int s, int t)
{
    vector<int> ans;
    do{
        ans.push_back(t);
        t = par[t];
    }while(t != -1);
    printf("%d",ans[ans.size()-1]);
    for(int i=ans.size()-2; i>=0; i--)
        printf(" %d",ans[i]);
    printf("\n");
}
int main()
{
    int tc,n,m,a,b,x,y,s,t;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%d",&n);
        scanf("%d",&a);
        x = y = s = a;
        for(int i=2; i<=n; i++){
            scanf("%d",&b);
            if(b<x) x = b;
            if(b>y) y = b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            a = b;
        }
        t = b;
        for(int i=x; i<=y; i++){
            sort(adj[i].begin(), adj[i].end());
            vis[i] = 0;
            par[i] = -1;
        }
        bfs(s,t);
        printf("Case %d:\n", cs);
        printPath(s,t);
        for(int i=x; i<=y; i++){
            adj[i].clear();
        }
    }

    return 0;
}
