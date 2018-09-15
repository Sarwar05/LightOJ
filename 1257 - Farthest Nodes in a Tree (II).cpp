
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
vector<int> cost(30001),cost2(30001);
int vis[30001];
int nod;
void bfs(int s)
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
            cost[u.v] = cost[x] + u.w;
            //cout<<x<<" to "<<u.v<<" cost is: "<<cost[u.v]<<endl;
            Q.push(u.v);
            if(cost[u.v]>tem){
                tem = cost[u.v];
                nod = u.v;
            }

        }
    }
}
int main()
{
    //freopen("out.txt","w", stdout);
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
        for(int i=0; i<n; i++) cost[i] = 0;
        bfs(0);
        for(int i=0; i<n; i++) cost[i] = 0;
        memset(vis,0,sizeof vis);
        bfs(nod);
        cost2 = cost;
        for(int i=0; i<n; i++) cost[i] = 0;
        memset(vis,0,sizeof vis);
        bfs(nod);
        printf("Case %d:\n",t);
        for(int i=0; i<n; i++)
            printf("%d\n", max(cost[i], cost2[i]));
        if(t != tc){
            for(int i=0; i<n; i++)
                adj[i].clear();
        }
    }

    return 0;
}
