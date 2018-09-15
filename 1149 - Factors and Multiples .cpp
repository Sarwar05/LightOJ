#include<bits/stdc++.h>
using namespace std;
#define mx 202
#define inf 1000000009
int source = 0, sink = 201;
vector<int> adj[mx];
int cap[mx][mx];
int passed[mx][mx];
int par[mx];
bool bfs()
{
    memset(par,-1,sizeof par);
    par[source ] = -5;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int from = q.front();
        q.pop();
        for(int i=0; i<adj[from].size(); i++){
            int to = adj[from][i];
            if(par[to]==-1 && cap[from][to] > passed[from][to]){
                par[to] = from;
                if(to==sink) return true;
                q.push(to);
            }
        }
    }
    return false;
}
int bpm()
{
    int maxFlow = 0,flow;
    while(bfs()){
        flow = inf;
        int to =  sink;
        while(to!=source){
            int from = par[to];
            flow = min(flow, cap[from][to] - passed[from][to]);
            to = from;
        }
        maxFlow+=flow;
        to =  sink;
        while(to!=source){
            int from = par[to];
            passed[from][to]+=flow;
            passed[to][from]-=flow;
            to = from;
        }
    }
    return maxFlow;
}
void refresh()
{
    for(int i=0; i<mx; i++) adj[i].clear();
    memset(cap,0,sizeof cap);
    memset(passed,0,sizeof passed);
}
unsigned int A[102],B[102];
void addEdge(int s, int t, int val)
{
    cap[s][t] = val;
    adj[s].push_back(t);
    adj[t].push_back(s);
}
int main()
{
    int tc,cs=1,n,m;
    scanf("%d",&tc);
    while(tc--){
        refresh();
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%u",&A[i]);
            addEdge(source,i,1);
        }
        scanf("%d",&m);
        for(int i=1; i<=m; i++){
            scanf("%u",&B[i]);
            addEdge(i+100,sink,1);
        }
        /// no A's multiple in B
        for(int i=1; i<=n; i++){/// A
            for(int j=1; j<=m; j++){/// B
                if(B[j]%A[i]==0){
                    addEdge(i,j+100,1);
                }
            }
        }
        printf("Case %d: %d\n",cs++,bpm());
    }
    return 0;
}
