#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/2
#define mx 102
vector<int> adj[mx];
int cap[mx][mx];
int passed[mx][mx];
int par[mx];
bool bfs(int source, int sink)
{
    memset(par,-1,sizeof par);
    par[source] = -2;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0 ;i<adj[u].size(); i++){
            int v = adj[u][i];
            if(par[v]==-1 && cap[u][v] - passed[u][v] >0){
                par[v] = u;
                if(v==sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int findMaxFlow(int source, int sink)
{
    int maxFlow = 0, flow;
    while(bfs(source,sink)){
        flow = inf;
        int prev, now = sink;
        while(now!=source){
            prev = par[now];
            flow = min(flow, cap[prev][now] - passed[prev][now]);
            now = prev;
        }
        maxFlow+=flow;
        now = sink;
        while(now!=source){
            prev = par[now];
            passed[prev][now]+=flow;
            passed[now][prev]-=flow;
            now = prev;
        }
    }
    return maxFlow;
}
int main()
{
    int tc,cs=1,a,b,c,n,m;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<mx; i++) adj[i].clear();
        memset(cap, 0, sizeof cap);
        memset(passed, 0, sizeof passed);
        scanf("%d%d",&n,&m);
        ///
        cap[1][50+1] = inf;
        cap[50+1][1] = inf;
        adj[1].push_back(50+1);
        adj[50+1].push_back(1);
        ///
        for(int i=2; i<= n-1; i++){
            scanf("%d",&a);
            cap[i][50+i] = a;
            cap[50+1][i] = a;
            adj[i].push_back(50+i);
            adj[50+i].push_back(i);
        }
        ///
        cap[n][50+n] = inf;
        cap[50+n][n] = inf;
        adj[n].push_back(50+n);
        adj[50+n].push_back(n);
        ///
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            cap[a+50][b] = c;
            cap[b+50][a] = c;
            adj[a+50].push_back(b);
            adj[b+50].push_back(a);
        }
        printf("Case %d: %d\n",cs++,findMaxFlow(1,n));
    }
    return 0;
}
