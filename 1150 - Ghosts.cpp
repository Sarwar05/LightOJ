#include<bits/stdc++.h>
using namespace std;
char grid[26][26];
int cost[26][26];
int id[26][26];
#define pii pair<int,int>
vector<int> human,ghost;
struct Edge
{
    int a;
    int b;
    int c;
    Edge(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};
vector<Edge> edge;
int mx;
int dirx[] = {1,-1,0,0};
int diry[] = {0,0,1,-1};
void bfs(int x, int y, int n)
{
    int start = id[x][y];
    queue< pii >q;
    q.push( make_pair(x,y) );
    memset(cost,-1,sizeof cost);
    cost[x][y] = 0;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = x+dirx[i];
            int yy = y+diry[i];
            if(xx>=0 && xx<n && yy>=0 && yy<n && grid[xx][yy]!='#' && cost[xx][yy]==-1){
                cost[xx][yy] = cost[x][y] + 1;
                q.push(make_pair(xx,yy));
                if(grid[xx][yy]=='H'){
                    edge.push_back(Edge(start,id[xx][yy],cost[xx][yy]));
                }
            }
        }
    }
}
int cap[630][630],passed[630][630],par[630];
vector<int> adj[630];
void build(int limit)
{
    for(int i=0; i<=mx+2; i++) adj[i].clear();
    for(int i=0; i<=mx+2; i++){
        for(int j=0; j<=mx+2; j++){
            cap[i][j] = passed[i][j] = 0;
        }
    }
    for(int i=0; i<ghost.size(); i++){
        cap[0][ ghost[i] ] = 1;
        adj[0].push_back(ghost[i]);
        adj[ghost[i]].push_back(0);
    }
    for(int i=0; i<human.size(); i++){
        cap[ human[i] ][mx+1] = 1;
        adj[mx+1].push_back(human[i]);
        adj[human[i]].push_back(mx+1);
    }
    for(int i=0; i<edge.size(); i++){
        if(edge[i].c<=limit){
            adj[ edge[i].a ].push_back(edge[i].b);
            adj[ edge[i].b ].push_back(edge[i].a);
            cap[ edge[i].a ][ edge[i].b ] = 1;
        }
    }
}
bool isAvailable(int source, int sink)
{
    for(int i=0; i<=mx+2; i++) par[i] = -1;
    queue<int> q;
    q.push(source);
    par[source] = -5;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(par[v]==-1 && (cap[u][v] - passed[u][v]) > 0){
                par[v] = u;
                if(v==sink) return true;
                q.push(v);
            }
        }
    }
    return (par[sink]!=-1);
}
int getFlow(int source=0, int sink=(mx+1))
{
    int maxFlow = 0;
    int flow;
    while(isAvailable(source,sink)){
        flow = 1000000;
        int now = sink;
        while(now!=source){
            int prev = par[now];
            flow = min(flow,cap[prev][now] - passed[prev][now]);
            now = prev;
        }
        maxFlow+=flow;
        now = sink;
        while(now!=source){
            int prev = par[now];
            passed[prev][now] += flow;
            passed[now][prev] -= flow;
            now = prev;
        }
    }
    return maxFlow;
}
int binarysearch()
{
    int lo = 1,hi = 630,mid;
    while(lo<hi){
        mid = (lo+hi)/2;
        build(mid);
        int flow = getFlow();
        if(flow>=human.size()){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    return (lo*2)+2;
}
int main()
{
    int tc,cs=1,n=1;
    scanf("%d",&tc);
    while(tc--){
        edge.clear();
        human.clear();
        ghost.clear();
        mx = 0;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                id[i][j] = ++mx;
            }
        }
        for(int i=0; i<n; i++){
            scanf("%s",grid[i]);
            for(int j=0; j<n; j++){
                if(grid[i][j]=='G') ghost.push_back(id[i][j]);
                if(grid[i][j]=='H') human.push_back(id[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='G'){
                    bfs(i,j,n);
                }
            }
        }
        printf("Case %d: ",cs++);
        build(1000000);
        if(getFlow()<human.size()) printf("Vuter Dol Kupokat\n");
        else{
            printf("%d\n",binarysearch());
        }
    }
    return 0;
}

