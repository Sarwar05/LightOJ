#include<bits/stdc++.h>
using namespace std;
#define mx 203
vector<int> adj[mx];
int cap[mx][mx];
int passed[mx][mx];
int par[mx];
int dist[mx][mx];
struct Node
{
    int at, cost;
    Node(int _at, int _cost)
    {
        at = _at;
        cost = _cost;
    }
    bool operator<(const Node& ob)const
    {
        return cost<ob.cost;
    }
};
bool BFS(int source, int sink, int limit)
{
    memset(par, -1, sizeof par);
    par[source] = -5;
    priority_queue<Node>pq;
    pq.push(Node(source,0));
    while(!pq.empty()){
        int u = pq.top().at;
        pq.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(par[v]==-1&&cap[u][v]-passed[u][v]>0&&dist[u][v]<=limit){
                par[v] = u;
                if(v==sink) return true;
                pq.push(Node(v,dist[0][v]));
            }
        }
    }
    return false;
}
int getMaxFlow(int source, int sink, int limit)
{
    int maxFlow = 0, flow;
    while(BFS(source,sink,limit)){
        flow = 1000000009;
        int prev, now = sink;
        while(now!=source){
            prev = par[now];
            flow = min(flow, cap[prev][now]-passed[prev][now]);
            now = prev;
        }
        maxFlow+=flow;
        if(maxFlow>=2)break;
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
int binarySearch(int lo, int hi, int source, int sink)
{

    int ans = hi,mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        memset(passed,0,sizeof passed);
        if(getMaxFlow(source,sink,mid)>=2){
            ans = min(ans,mid);
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return ans;
}
int main()
{
    int tc,cs=1,n,d,dst;
    char ch;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0;i<mx; i++) adj[i].clear();
        memset(cap,0,sizeof cap);
        scanf("%d%d",&n,&d);
        for(int i=1; i<=n; i++){
            scanf("%*c%c%*c%d",&ch,&dst);
            //cout<<ch<<" "<<dst<<endl;
            /// split that node
            cap[i][i+100] = (ch=='S') ? 1 : 2;
            adj[i].push_back(i+100);
            adj[i+100].push_back(i);
            dist[i][i+100] = dist[i+100][i] = 0;
            /// connect with source
            cap[0][i] = 2;
            adj[0].push_back(i);
            adj[i].push_back(0);
            dist[0][i] = dist[i][0] = dst;
            /// connect with sink
            cap[i+100][201] = 2;
            adj[i+100].push_back(201);
            adj[201].push_back(i+100);
            dist[201][i+100] = dist[i+100][201] = d-dst;
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                cap[i+100][j] = 2;
                adj[i+100].push_back(j);
                adj[j].push_back(i+100);
                dist[i+100][j] = dist[j][i+100] = dist[0][j] - dist[0][i];
            }
        }
        printf("Case %d: %d\n",cs++,binarySearch(1,d,0,201));
    }
    return 0;
}
/**
3
1 10
B-5
1 10
S-5
2 10
B-3 S-6
*/
