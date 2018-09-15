#include<bits/stdc++.h>
using namespace std;
#define mx 205
struct Edge
{
    int u;
    int v;
    int cost;
    Edge(int a, int b, int c)
    {
        u = a;
        v = b;
        cost = c;
    }
};
priority_queue<Edge> node;
bool operator<(Edge a, Edge b)
{
    return a.cost > b.cost;
}
int par[mx];
void init(int n)
{
    for(int i=0; i<=n; i++){
        par[i] = i;
    }
}
int findPar(int a)
{
    if(par[a]!= a) par[a] = findPar(par[a]);
    return par[a];
}
int kruskal(int n)
{
    init(n);
    int ret = 0;
    priority_queue<Edge> mst;
    while(!node.empty()){
        Edge e = node.top();
        node.pop();
        int x = e.u;
        int y = e.v;
        int a = findPar(x);
        int b = findPar(y);
        if(a != b){
            mst.push(Edge(x,y,e.cost));
            ret += e.cost;
            par[a] = par[b];
        }
    }
    node = mst;
    int p = findPar(1);
    for(int i=2; i<=n; i++){
        if(findPar(i) != p){
            ret = -1;
            break;
        }
    }
    printf("%d\n",ret);
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc; scanf("%d",&tc);
    int n,w,a,b,c;
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&w);
        printf("Case %d:\n",t);
        for(int i=1; i<=w; i++){
            scanf("%d%d%d",&a,&b,&c);
            node.push(Edge(a,b,c));
            node.push(Edge(b,a,c));
            kruskal(n);
        }
        if(t!= tc)
            node = priority_queue <Edge>();
    }
}
 
 
 
