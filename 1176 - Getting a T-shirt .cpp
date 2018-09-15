#include<bits/stdc++.h>
#define inf INT_MAX/2
using namespace std;
char str[5];
int getID()
{
    if(strcmp(str,"XS")==0) return 1;
    if(strcmp(str,"S")==0) return 2;
    if(strcmp(str,"M")==0) return 3;
    if(strcmp(str,"L")==0) return 4;
    if(strcmp(str,"XL")==0) return 5;
    if(strcmp(str,"XXL")==0) return 6;
}
#define mx 110
vector<int> adj[mx];
int cap[mx][mx];
int passed[mx][mx];
int par[mx];
bool bfs(int source, int sink)
{
    memset(par, -1,sizeof par);
    par[source] = -3;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(par[v]==-1 && cap[u][v] - passed[u][v] >0 ){
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
    while(bfs(source, sink)){
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
void refresh()
{
    memset(cap,0,sizeof cap);
    memset(passed, 0, sizeof passed);
    for(int i=0; i<mx; i++)
        adj[i].clear();
}
int main()
{
    int tc,cs=1,n,m,a,b,c;
    scanf("%d",&tc);
    while(tc--){
        refresh();
        scanf("%d%d",&n,&m);
        for(int i=1; i<=6; i++){
            adj[0].push_back(i);
            adj[i].push_back(0);
            cap[0][i] = n;
        }
        for(int i=1; i<=m; i++){
            scanf("%s",str);
            a = getID();
            adj[a].push_back(i+7);
            adj[i+7].push_back(a);
            cap[a][i+7]++;

            scanf("%s",str);
            b = getID();
            adj[b].push_back(i+7);
            adj[i+7].push_back(b);
            cap[b][i+7]++;

            adj[i+7].push_back(108);
            adj[108].push_back(i+7);
            cap[i+7][108]++;
        }
        printf("Case %d: %s\n",cs++, findMaxFlow(0,108) == m ? "YES" : "NO");
    }
    return 0;
}
