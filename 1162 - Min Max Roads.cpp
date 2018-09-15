#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define pii pair<int,int>
int table[mx][17],maxw[mx][17],minw[mx][17];
int level[mx];
vector<int> adj[mx],cost[mx];
void dfs(int u, int p, int l, int w)
{
    table[u][0] = p;
    maxw[u][0] = w;
    minw[u][0] = w;
    level[u] = l;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p) continue;
        dfs(v,u,l+1,cost[u][i]);
    }
}
void query(int p,int q)
{
    int maxret = 0,minret = 10000000;
    if(level[p]>level[q]) swap(p,q);
    for(int i=16; i>=0; i--){
        if(level[q]-(1<<i)>=level[p]){
            maxret = max(maxret,maxw[q][i]);
            minret = min(minret,minw[q][i]);
            q = table[q][i];
        }
    }
    if(p!=q){
        for(int i=16; i>=0; i--){
            if(table[p][i]!=-1 && table[p][i]!=table[q][i]){
                maxret = max(maxret,maxw[q][i]);
                minret = min(minret,minw[q][i]);
                maxret = max(maxret,maxw[p][i]);
                minret = min(minret,minw[p][i]);
                p = table[p][i];
                q = table[q][i];
            }
        }
        maxret = max(maxret,maxw[q][0]);
        minret = min(minret,minw[q][0]);
        maxret = max(maxret,maxw[p][0]);
        minret = min(minret,minw[p][0]);
    }
    printf("%d %d\n",minret,maxret);
}
int main()
{
    int tc,n,a,b,c,cs=1,q;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            cost[i].clear();
        }
        for(int i=1; i<n; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        memset(table,-1,sizeof table);
        dfs(1,-1,0,0);
        for(int j=1; j<=16; j++){
            for(int i=1; i<=n; i++){
                if(table[i][j-1]!=-1){
                    table[i][j] = table[ table[i][j-1] ][j-1];
                    maxw[i][j] = max(maxw[i][j-1],maxw[ table[i][j-1] ][j-1]);
                    minw[i][j] = min(minw[i][j-1],minw[ table[i][j-1] ][j-1]);
                }
            }
        }
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&a,&b);
            query(a,b);
        }
    }
    return 0;
}