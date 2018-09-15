#include<bits/stdc++.h>
using namespace std;
#define mx 102
int dist[mx];
struct Edge
{
    int u;
    int v;
    int w;
    Edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
vector<Edge> in;
int BellmanFord(int node,int edge)
{
    for(int i=0; i<=node; i++) dist[i] = 100000000;
    dist[0] = 0;
    for(int step = 1; step<=node; step++){
        int upd = 0;
        for(int i=0; i<edge; i++){
            if(dist[ in[i].u ] > dist[ in[i].v ] + in[i].w ){
                dist[ in[i].u ] = dist[ in[i].v ] + in[i].w;
                upd = 1;
                if(step==node) return 1;
            }
        }
        if(upd==0) return 0;
    }
}
int main()
{
    int tc,cs=1,n,r,a,b,i,e,p;
    scanf("%d",&tc);
    while(tc--){
        in.clear();
        scanf("%d%d%d",&n,&r,&p);
        for(int j=1; j<=r; j++){
            scanf("%d%d%d%d",&a,&b,&i,&e);
            in.push_back(Edge(a,b,e*p-i));
        }
        printf("Case %d: %s\n",cs++, BellmanFord(n,r) ? "YES" : "NO");
    }
    return 0;
}
