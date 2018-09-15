#include<bits/stdc++.h>
using namespace std;
#define mx 101
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
vector<Edge> node;
bool comp(Edge a, Edge b)
{
    return a.cost < b.cost;
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
int kruskal(int n,int sz)
{
    init(n);
    int ret = 0;
    for(int i = 0; i<sz; i++){
        int a = node[i].u;
        int b = node[i].v;
        a = findPar(a);
        b = findPar(b);
        if(a != b){
            ret += node[i].cost;
            par[a] = par[b];
        }
    }
    return ret;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc; scanf("%d",&tc);
    int n,u,v,w;
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        while(scanf("%d%d%d",&u,&v,&w), u|v|w){
            node.push_back(Edge(u,v,w));
            node.push_back(Edge(v,u,w));
        }
        int ans = 0;
        sort(node.begin(), node.end(),comp);
        int sz = node.size();
        ans+=kruskal(n,sz);
        reverse(node.begin(), node.end());
        ans+=kruskal(n,sz);
        printf("Case %d: ",t);
        if(ans%2==1)
            printf("%d/2\n",ans);
        else printf("%d\n",ans/2);
        if(t!= tc)
            node.clear();
    }
}