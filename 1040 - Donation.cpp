#include<bits/stdc++.h>
using namespace std;
#define mx 55
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
    int tc,n,a;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        int total = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d",&a);
                total+=a;
                if(a != 0){
                    node.push_back(Edge(i,j,a));
                    node.push_back(Edge(j,i,a));
                }
            }
        }
        sort(node.begin(), node.end(), comp);
        int mst = kruskal(n,node.size());
        int ans = total-mst;
        int p = findPar(1);
        for(int i=2;i<=n; i++){
            if(findPar(i) != p){
                ans = -1;
                break;
            }
        }
        printf("Case %d: %d\n",t,ans);
        if(t != tc) node.clear();
    }
    return 0;
}
 