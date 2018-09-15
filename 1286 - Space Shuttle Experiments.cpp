/// First of all, we connect the source point and the experiment, the capacity is the corresponding income,
/// the edge is connected between the instrument and the sink, the capacity is the carrying cost, and then
/// the edge is connected between the corresponding experiment and the instrument.
/// For experimental income (maximum value can also be used, as long as greater than or equal to the
/// experimental income can be guaranteed), the meaning of the maximum flow at this time is the cost that the
/// transportation instrument can pay. What is the cost to pay? That is, if certain instruments are used to make profits,
/// then the cost of carrying these instruments will be lost. If they cannot be profitable,
/// they will pay the fullest amount of the corresponding experiment's income, and no more (guaranteed not to lose money).
/// For profitable projects, revenue minus costs is naturally a profit. For unprofitable projects, revenue minus the cost
/// is equal to 0 (because you said that you paid all the revenues before). The significance is that you do not do this
/// experiment (losing money at a loss). . So, the result is total revenue minus maximum flow
///
#include<bits/stdc++.h>
using namespace std;
#define mx 202
#define inf 1000000009
vector<int> adj[mx];
int cap[mx][mx],passed[mx][mx],par[mx];
int source = 0,sink = 201;
bool bfs()
{
    memset(par,-1,sizeof par);
    queue<int> q;
    q.push(source);
    par[source] = -5;
    while(!q.empty()){
        int from =q.front();
        q.pop();
        for(int i=0; i<adj[from].size(); i++){
            int to = adj[from][i];
            if(par[to]==-1 && cap[from][to] > passed[from][to]){
                par[to] =   from;
                if(to == sink) return true;
                q.push(to);
            }
        }
    }
    return false;
}
int findMaxFlow()
{
    int maxFlow = 0, flow;
    while(bfs()){
        flow = inf;
        int now = sink;
        while(now!=source){
            int prev = par[now];
            flow = min(flow, cap[prev][now] - passed[prev][now]);
            now = prev;
        }
        maxFlow+=flow;
        now = sink;
        while(now!=source){
            int prev = par[now];
            passed[prev][now]+=flow;
            passed[now][prev]-=flow;
            now = prev;
        }
    }
    return maxFlow;
}
int main()
{
    int tc,n,m,a,b,c,cs=1,q;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<mx; i++)adj[i].clear();
        memset(cap,0,sizeof cap);
        memset(passed,0,sizeof passed);
        scanf("%d%d",&m,&n);
        int total = 0;
        for(int i=1; i<=m; i++){
            scanf("%d",&a);
            cap[source][i] = a;
            adj[source].push_back(i);
            adj[i].push_back(source);
            total+=a;
        }
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            cap[100+i][sink] = a;
            adj[100+i].push_back(sink);
            adj[sink].push_back(100+i);
        }
        for(int j=1; j<=m; j++){
            scanf("%d",&q);
            while(q--){
                scanf("%d",&a);
                cap[j][100+a] = inf;
                adj[j].push_back(100+a);
                adj[100+a].push_back(j);
            }
        }
        printf("Case %d: %d\n",cs++,total-findMaxFlow());
    }
    return 0;
}
