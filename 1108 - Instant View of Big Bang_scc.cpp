#include<bits/stdc++.h>
using namespace std;
#define mx 1002
vector<int> adj[mx],rev[mx];
vector<int> rcost[mx];
stack<int> st;
int vis[mx],dist[mx];
struct Edge
{
    int u;
    int v;
    int w;
    Edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
void dfs1(int s)
{
    vis[s] = 1;
    for(int i=0; i<(int)adj[s].size(); i++){
        int v = adj[s][i];
        if(vis[v]==0)dfs1(v);
    }
    st.push(s);
}
vector<Edge> cycle;
vector<int> visit;
int color;
void dfs2(int s)
{
    vis[s] = color;
    for(int i=0; i<(int)rev[s].size(); i++){
        int v = rev[s][i];
        if(vis[v]==0){
            cycle.push_back(Edge(v,s,rcost[s][i]));
            dfs2(v);
        }
        else if(vis[v]==color){
            cycle.push_back(Edge(v,s,rcost[s][i]));
        }
    }
    visit.push_back(s);
}
void refresh()
{
    for(int i=0; i<mx; i++){
        adj[i].clear();
        rev[i].clear();
        rcost[i].clear();
        dist[i] = 100000000;
    }
}
int negativeCycle(int node, int edge)
{
    dist[ visit[0] ] = 0;
    for(int i=1; i<=node; i++){
        int upd = 0;
        for(int j=0; j<edge; j++){
            int u = cycle[j].u;
            int v = cycle[j].v;
            int w = cycle[j].w;
            if(dist[v]>dist[u]+w){
                upd = 1;
                dist[v] = dist[u]+w;
                if(i==node) return 1;
            }
        }
        if(upd==0) return 0;
    }
    //return 0;
}
void dfs(int s)
{
    vis[s]=1;
    for(int i=0; i<(int)rev[s].size(); i++){
        int v = rev[s][i];
        if(vis[v]==0)
            dfs(v);
    }
}
int main()
{
    int tc,cs=1,a,b,c,n,m;
    scanf("%d",&tc);
    while(tc--){
        refresh();
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back(b);
            rev[b].push_back(a);
            rcost[b].push_back(c);
        }
        printf("Case %d:",cs++);
        memset(vis,0,sizeof vis);
        for(int i=0; i<n;i++){
            if(vis[i]==0)
                dfs1(i);
        }
        memset(vis,0,sizeof vis);
        vector<int> bang;
        color = 0;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(vis[x]==0){
                cycle.clear();
                visit.clear();
                ++color;
                dfs2(x);
                if(negativeCycle(visit.size(), cycle.size())){
                    for(int i=0; i<visit.size(); i++){
                        bang.push_back(visit[i]);
                    }
                }
            }
        }
        if(bang.empty()){
            printf(" impossible\n");
        }
        else{
            memset(vis,0,sizeof vis);
            for(int i=0; i<bang.size(); i++){
                if(vis[i]==0) dfs(bang[i]);
            }
            for(int i=0; i<n; i++){
                if(vis[i]==1) printf(" %d",i);
            }
            printf("\n");
        }
    }
    return 0;
}
