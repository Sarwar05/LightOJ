#include<bits/stdc++.h>
using namespace std;
#define mx 10005
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
void kruskal(int n,int sz, int build)
{
    init(n);
    int ret = 0;
    int cunt_a = 1;
    for(int i = 0; i<sz; i++){
        int a = node[i].u;
        int b = node[i].v;
        a = findPar(a);
        b = findPar(b);
        if(a != b && node[i].cost <= build){
            ret += node[i].cost;
            if(node[i].cost == build){
                cunt_a++;
            }
 
            par[a] = par[b];
        }
    }
    set<int> st;
    for(int i=1; i<=n; i++){
        int x = findPar(i);
        st.insert(x);
    }
 
    sz = st.size();
    int ap = cunt_a+st.size()-1;
    ret = ret + sz*build;
    printf("%d %d\n",ret,ap);
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc; scanf("%d",&tc);
    int n,m,a,x,y,c;
    for(int t=1; t<=tc; t++){
        scanf("%d%d%d",&n,&m,&a);
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&x,&y,&c);
            node.push_back(Edge(x,y,c));
            node.push_back(Edge(y,x,c));
        }
        sort(node.begin(), node.end(),comp);
        int sz = node.size();
        printf("Case %d: ",t);
        kruskal(n,sz,a);
        if(t!= tc)
            node.clear();
    }
    return 0;
}