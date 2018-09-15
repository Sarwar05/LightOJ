#include<bits/stdc++.h>
using namespace std;
#define mx 5005
#define inf 100000000
vector<int> adj[mx], wt[mx];
int cost[2][mx];
struct str
{
    int st;
    int u;
    int w;
    str(int _st,int _u, int _w)
    {
        st = _st;
        u = _u;
        w = _w;
    }
    bool operator<(const str& ob) const
    {
        return w<ob.w;
    }
};
int dij(int s, int t)
{
    cost[0][s] = 0;
    priority_queue<str>pq;
    pq.push(str(0,s,0));//pq.push(str(1,s,0));
    while(!pq.empty()){
        str ob = pq.top();
        pq.pop();
        int st = ob.st;
        int u = ob.u;
        int w = ob.w;
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            int cv = wt[u][i];
            int nc = cost[st][u] + cv;
            if(cost[0][v] > nc){
                cost[1][v] = cost[0][v];
                cost[0][v] = nc;
                pq.push(str(0,v,cost[0][v]));
                pq.push(str(1,v,cost[1][v]));
            }
            else if(nc > cost[0][v] && nc<cost[1][v]){
                cost[1][v] = nc;
                pq.push(str(1,v,cost[1][v]));
            }
            //cout<<"cost n = "<<cost[0][t]<<" "<<cost[1][t]<<endl;
        }
    }
    return cost[1][t];
}
int main()
{
    int tc,n,r,a,b,c,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&r);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            wt[i].clear();
            cost[1][i] = cost[0][i] = inf;
        }
        for(int i=0; i<r; i++){
            scanf("%d%d%d",&a, &b, &c);
            //cout<<"a b c: "<<a<<" "<<b<<" "<<c<<endl;
            adj[a].push_back(b);
            adj[b].push_back(a);
            wt[a].push_back(c);
            wt[b].push_back(c);
        }
        printf("Case %d: %d\n",cs++, dij(1,n));
    }
    return 0;
}
