#include<bits/stdc++.h>
using namespace std;
#define mx 50005
vector<int>adj[mx],cost[mx];
int table[mx][17],weight[mx][17];
int level[mx],par[mx];
struct Edge
{
    int a,b,c;
    bool operator<(const Edge& ob)const
    {
        return c<ob.c;
    }
};
vector<Edge> edge;
int findPar(int r)
{
    if(par[r]==r) return r;
    else return par[r] = findPar(par[r]);
}
void dfs(int u, int p, int l, int w)
{
    table[u][0] = p;
    level[u] = l;
    weight[u][0] = w;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p) continue;
        dfs(v,u,l+1,cost[u][i]);
    }
}
void generateTree(int n)
{
    for(int i=1; i<=n; i++) par[i] = i;
    sort(edge.begin(),edge.end());
    int cnt=1;
    for(int i=0; i<edge.size(); i++){
        int a = edge[i].a;
        int b = edge[i].b;
        int c = edge[i].c;
        int u = findPar(a);
        int v = findPar(b);
        if(u!=v){
            ++cnt;
            par[u] = v;
            adj[a].push_back(b);
            adj[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        if(cnt==n)break;
    }
    memset(table,-1,sizeof table);
    dfs(1,-1,0,0);
    for(int j=1; j<=16; j++){
        for(int i=1; i<=n; i++){
            if(table[i][j-1]!=-1){
                table[i][j] = table[ table[i][j-1] ][j-1];
                weight[i][j] = max(weight[ table[i][j-1] ][j-1],weight[i][j-1]);
            }
        }
    }
}
int query(int p, int q)
{
    if(level[p]>level[q]) swap(p,q);
    int ret = 0;
    for(int i=16; i>=0; i--){
        if(level[q] - (1<<i)>=level[p]){
            ret = max(ret,weight[q][i]);
            q = table[q][i];
        }
    }
    if(p==q) return ret;
    for(int j=16; j>=0; j--){
        if(table[p][j]!=-1 && table[p][j]!=table[q][j]){
            ret = max(ret,weight[p][j]);
            ret = max(ret,weight[q][j]);
            p = table[p][j];
            q = table[q][j];
        }
    }
    ret = max(ret,weight[p][0]);
    ret = max(ret,weight[q][0]);
    return ret;
}
int main()
{
    int tc,cs=1,n,m,a,b,q;
    Edge ob;
    scanf("%d",&tc);
    while(tc--){
        edge.clear();
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            cost[i].clear();
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&ob.a,&ob.b,&ob.c);
            edge.push_back(ob);
        }
        generateTree(n);
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&a,&b);
            printf("%d\n",query(a,b));
        }
    }
    return 0;
}