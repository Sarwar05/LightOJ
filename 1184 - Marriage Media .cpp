#include<bits/stdc++.h>
using namespace std;
#define mx 102
#define inf 1000000009
int source = 0, sink = 101;
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
void addEdge(int s, int t, int val)
{
    cap[s][t] = val;
    adj[s].push_back(t);
    adj[t].push_back(s);
}
struct Info
{
    int height;
    int age;
    int devorce;
}men[51], women[51];
int main()
{
    int tc,cs=1,n,m;
    scanf("%d",&tc);
    while(tc--){
        refresh();
        scanf("%d",&m);scanf("%d",&n);
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&men[i].height,&men[i].age, &men[i].devorce);
            addEdge(source,i,1);
        }
        for(int i=1; i<=n; i++){
            scanf("%d%d%d",&women[i].height,&women[i].age, &women[i].devorce);
            addEdge(50+i,sink,1);
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(abs(men[i].height-women[j].height)<=12 && abs(men[i].age-women[j].age)<=5 && men[i].devorce==women[j].devorce){
                    addEdge(i,j+50,1);
                }
            }
        }
        printf("Case %d: %d\n",cs++,bpm());
    }
    return 0;
}
