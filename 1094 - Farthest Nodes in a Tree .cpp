#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v;
    int w;
    node(int _v, int _w)
    {
        v = _v;
        w = _w;
    }
};
vector<node> adj[30001];
int cost[30001];
int vis[30001];
int nod;
int bfs(int s)
{
    nod = s;
    int tem = 0;
    vis[s] = 1;
    queue<int> Q;
    Q.push(s);
    while(! Q.empty()){
        int x = Q.front();
        Q.pop();
        int sz = adj[x].size();
        for(int i=0; i<sz; i++){
            node u = adj[x][i];
            if(vis[u.v]==1) continue;
            else vis[u.v] = 1;
            cost[u.v] = cost[x]+u.w;
            //cout<<x<<" to "<<u.v<<" cost is: "<<cost[u.v]<<endl;
            Q.push(u.v);
            if(cost[u.v]>tem){
                tem = cost[u.v];
                nod = u.v;
            }

        }
    }

    return tem;
}
int main()
{
    int tc,n,a,b,w;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        for(int i=1; i<n; i++){
            scanf("%d%d%d",&a,&b,&w);
            adj[a].push_back(node(b,w));
            adj[b].push_back(node(a,w));
        }

        memset(vis,0,sizeof vis);
        memset(cost, 0, sizeof cost);
        int ans = bfs(0);
        memset(cost, 0, sizeof cost);
        memset(vis,0,sizeof vis);
        ans = bfs(nod);

        printf("Case %d: %d\n",t,ans);
        if(t != tc){
            for(int i=0; i<n; i++)
                adj[i].clear();
        }
    }

    return 0;
}
