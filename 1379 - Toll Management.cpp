#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define inf 1000000000
vector<int> adj[mx],cost[mx];
vector<int> rev[mx],rcost[mx];
int dist1[mx],dist2[mx];
struct Node
{
    int now;
    int weight;
    Node(int a, int b)
    {
        now = a;
        weight = b;
    }
    bool operator<(const Node& ob) const
    {
        return weight>ob.weight;
    }
};
void dij1(int s)
{
    priority_queue<Node> pq;
    pq.push(Node(s,0));
    dist1[s] = 0;
    while(!pq.empty()){
        int u = pq.top().now;
        int w = pq.top().weight;
        pq.pop();
        for(int i=0; i<(int)adj[u].size(); i++){
            int v = adj[u][i];
            int add = cost[u][i];
            if(dist1[v]> w+add){
                dist1[v] = w+add;
                pq.push(Node(v,dist1[v]));
            }
        }
    }
}
void dij2(int s)
{
    priority_queue<Node> pq;
    pq.push(Node(s,0));
    dist2[s] = 0;
    while(!pq.empty()){
        int u = pq.top().now;
        int w = pq.top().weight;
        pq.pop();
        for(int i=0; i<(int)rev[u].size(); i++){
            int v = rev[u][i];
            int add = rcost[u][i];
            if(dist2[v]> w+add){
                dist2[v] = w+add;
                pq.push(Node(v,dist2[v]));
            }
        }
    }
}
int main()
{
    int n,m,tc, cs=1,a,b,c,s,t,p;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            cost[i].clear();
            rev[i].clear();
            rcost[i].clear();
            dist1[i] = dist2[i] = inf;
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back(b);
            cost[a].push_back(c);
            rev[b].push_back(a);
            rcost[b].push_back(c);
        }
        dij1(s);
        dij2(t);
        int ans = -1;
        for(int i=1; i<=n; i++){
            a = i;
            for(int j=0; j<adj[a].size(); j++){
                b = adj[a][j];
                c = cost[a][j];
                if(dist1[a] + c + dist2[b] <= p){
                    ans = max(ans, c);
                }
            }
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
