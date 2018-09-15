#include<bits/stdc++.h>
using namespace std;
#define mx 205
vector<int> adj[mx];
int cap[mx][mx], passed[mx][mx], par[mx];
bool bfs(int source, int sink)
{
    memset(par,-1,sizeof par);
    par[source] = -5;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(par[v]==-1 && cap[u][v]-passed[u][v] > 0){
                par[v] = u;
                if(v==sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int findFlow(int source, int sink)
{
    int maxFlow = 0,flow;
    while(bfs(source,sink)){
        flow = INT_MAX/2;
        int now=sink,prev;
        while(now!=source){
            prev = par[now];
            flow = min(flow,cap[prev][now] - passed[prev][now]);
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
    int tc,cs=1,n,m,a,b,c,x,y,r;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<mx; i++) adj[i].clear();
        memset(cap, 0, sizeof cap);
        memset(passed, 0, sizeof passed);
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&r);
            adj[i].push_back(i+100);
            cap[i][i+100] += r;
            adj[i+100].push_back(i);
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            cap[a+100][b]+=c;
            adj[a+100].push_back(b);
            adj[b].push_back(a+100);
        }
        scanf("%d%d",&x,&y);
        while(x--){
            scanf("%d",&a);
            cap[0][a]=100000000;
            adj[0].push_back(a);
            adj[a].push_back(0);
        }
        while(y--){
            scanf("%d",&a);
            cap[a+100][n+101]=100000000;
            adj[a+100].push_back(n+101);
            adj[n+101].push_back(a+100);
        }
        printf("Case %d: %d\n",cs++, findFlow(0,n+101));
    }
    return 0;
}
