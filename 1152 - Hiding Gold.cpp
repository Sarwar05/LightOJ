#include<bits/stdc++.h>
using namespace std;
#define mx 20*20*4 + 5
#define inf 1000000009
int source = 0, sink = mx-2;
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
void addEdge(int s, int t, int val=1)
{
    cap[s][t] = val;
    adj[s].push_back(t);
    adj[t].push_back(s);
}
int dirx[] = {0,0,-1,1};
int diry[] = {1,-1,0,0};
char grid[22][22];
int id[22][22];
int color[22][22] = {0};
int main()
{
    int tc,cs=1,n,m;
    tc=1;
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            id[i][j] = tc++;
        }
    }
    for(int i=0; i<20; i++){
        if(i%2==0){
            for(int j=0; j<20; j+=2){
                color[i][j] = 1;
            }
        }
        else{
            for(int j=1; j<20; j+=2){
                color[i][j] = 1;
            }
        }
    }
//    for(int i=0; i<20; i++){
//        for(int j=0; j<20; j++){
//            printf("%d ",id[i][j]);
//            //printf("%d ",color[i][j]);
//        }
//        printf("\n");
//    }
    scanf("%d",&tc);
    while(tc--){
        refresh();
        scanf("%d%d",&m,&n);
        for(int i=0; i<m; i++)scanf("%s",grid[i]);
        int tot = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='*'){
                    if(color[i][j]==1) addEdge(source,id[i][j]);
                    else addEdge(id[i][j],sink);
                    tot++;
                    for(int k=0; k<4; k++){
                        int xx = i+dirx[k];
                        int yy = j+diry[k];
                        if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]=='*'){
                            if(color[i][j]==1)addEdge(id[i][j],id[xx][yy]);
                            else addEdge(id[xx][yy],id[i][j]);
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",cs++,tot-bpm());
    }
    return 0;
}
