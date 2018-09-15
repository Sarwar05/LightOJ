#include<bits/stdc++.h>
using namespace std;
#define mx 101
#define inf INT_MAX/2
int cap[mx][mx];
int passed[mx][mx];
vector<int> adj[mx];
int par[mx];
int curr[mx];
int bfs(int s, int t)
{
    memset(par, -1, sizeof par);
    memset(curr, 0, sizeof curr);
    queue<int> q;
    q.push(s);
    par[s] = -2;
    curr[s] = inf;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(par[v]==-1 && (cap[u][v] - passed[u][v] > 0)){
                par[v] = u;
                curr[v] = min(curr[u],cap[u][v]-passed[u][v]);
                if(v==t) return curr[v];
                q.push(v);
            }
        }
    }
    return 0;
}
int findMaxFlow(int s, int t)
{
    int maxFlow = 0,flow;
    while(true){
        flow = bfs(s,t);
        if(!flow) break;
        maxFlow+=flow;
        int now = t;
        while(now!=s){
            int prev = par[now];
            passed[prev][now] += flow;
            passed[now][prev] -= flow;
            now = prev;
        }
    }
    return maxFlow;
}
int main()
{
    int n,m,a,b,c,s,t;
    int  tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        memset(cap,0,sizeof cap);
        memset(passed,0,sizeof passed);
        scanf("%d",&n);
        scanf("%d%d%d",&s,&t,&m);
        for(int i=0; i<=n; i++) adj[i].clear();
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            cap[a][b] +=c;
            cap[b][a] += c;
        }
        printf("Case %d: %d\n",cs++,findMaxFlow(s,t));
    }
    return 0;
}

