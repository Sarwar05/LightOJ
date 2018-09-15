#include<bits/stdc++.h>
using namespace std;
#define mx 1002
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
vector<Edge> normal, transpose;
vector<int> rev[mx];
int dist1[mx],dist2[mx], arr1[mx],arr2[mx],vis[mx],cycle[mx];
void refresh()
{
    for(int i=0; i<mx; i++){
        arr1[i] = arr2[i] = 0;
        dist1[i] = dist2[i] = 10000000;
        rev[i].clear();
        vis[i] = 0;
        cycle[i] = 0;
    }
    normal.clear();
    transpose.clear();
}
int neg;
void relax1(int node, int edge)
{
    dist1[0] = 0;
    for(int step=1; step<=node; step++){
        int upd = 0;
        for(int i=0; i<edge; i++){
            int u = normal[i].u;
            int v = normal[i].v;
            int w = normal[i].w;
            if(dist1[v]> dist1[u]+w){
                upd = 1;
                if(step==node){
                    neg = 1;
                    arr1[u]++;
                    arr1[v]++;
                }
                dist1[v] =  dist1[u]+w;
            }
        }
        if(upd==0) return;
    }
}
void relax2(int node, int edge)
{
    dist2[0] = 0;
    for(int step=1; step<=node; step++){
        int upd = 0;
        for(int i=0; i<edge; i++){
            int u = transpose[i].u;
            int v = transpose[i].v;
            int w = transpose[i].w;
            if(dist2[v]> dist2[u]+w){
                upd = 1;
                if(step==node){
                    arr2[u]++;
                    arr2[v]++;
                }
                dist2[v] =  dist2[u]+w;
            }
        }
        if(upd==0) return;
    }
}
int hit;
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
            normal.push_back(Edge(a,b,c));
            transpose.push_back(Edge(b,a,c));
            rev[b].push_back(a);
        }
        printf("Case %d:",cs++);
        neg = 0;
        relax1(n,m);
        if(neg==0){
            printf(" impossible\n");
            continue;
        }
        relax2(n,m);
        for(int i=0; i<n; i++) if(arr1[i]>0 && arr2[i]>0) dfs(i);
        for(int i=0; i<n; i++) if(vis[i]==1) printf(" %d",i);
        printf("\n");
    }
    return 0;
}
