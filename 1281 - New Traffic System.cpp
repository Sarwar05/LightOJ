#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define inf 20000000
struct node
{
    int type;
    int v;
    int w;
    node(int _type, int _v, int _w)
    {
        type = _type;
        v = _v;
        w = _w;
    }
    bool operator<(const node& ob)const
    {
        return w>ob.w;
    }
};
vector<int>adj[mx], xtra[mx],adj_cost[mx], xtra_cost[mx];
int d, cost[mx][12];
void dij(int s, int t)
{
    for(int i=0; i<=d; i++) cost[s][i] = 0;
    cost[s][0] = 0;
    priority_queue<node> pq;
    pq.push(node(0,s,0));
    while(!pq.empty()){
        int type = pq.top().type;
        int u = pq.top().v;
        int wt = pq.top().w;
        if(u==t && wt == cost[u][type]){
            return;
        }
        pq.pop();
        for(int i=0; i<(int)adj[u].size(); i++){
            int v = adj[u][i];
            int w = adj_cost[u][i];
            if(cost[v][type] > wt+w){
                cost[v][type] = wt+w;
                pq.push(node(type, v, wt+w));
            }
        }
        if(type==d) continue;
        for(int i=0; i<(int)xtra[u].size(); i++){
            int v = xtra[u][i];
            int w = xtra_cost[u][i];
            if(cost[v][type+1] > wt+w){
                cost[v][type+1] = wt+w;
                pq.push(node(type+1, v, wt+w));
            }
        }
    }
}
int main()
{
    int tc,n,k,m,cs=1,a,b,c;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=0; i<n; i++){
            adj[i].clear();
            xtra[i].clear();
            adj_cost[i].clear();
            xtra_cost[i].clear();
            for(int j=0; j<=d; j++)
                cost[i][j] = inf;
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&a, &b, &c);
            adj[a].push_back(b);
            adj_cost[a].push_back(c);
        }
        for(int i=1; i<=k; i++){
            scanf("%d%d%d",&a, &b, &c);
            xtra[a].push_back(b);
            xtra_cost[a].push_back(c);
        }
        dij(0,n-1);
        int ans = inf;
        for(int i=0; i<=d; i++){
            ans = min(ans, cost[n-1][i]);
        }
        printf("Case %d: ",cs++);
        if(ans==inf){
            printf("Impossible\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
