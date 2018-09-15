#include<bits/stdc++.h>
using namespace std;
#define mx 51
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
    int cunt = 1;
    for(int i = 0; i<sz; i++){
        int a = node[i].u;
        int b = node[i].v;
        a = findPar(a);
        b = findPar(b);
        if(a != b){
            ret += node[i].cost;
            par[a] = par[b];
            cunt++;
        }
        if(cunt==n) break;
    }
    return ret;
}
map< string , int> mp;
int main()
{
    //freopen("out.txt","w",stdout);
    int tc; scanf("%d",&tc);
    string a,b;
    int u,v,n,w;
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        int val=0;
        for(int i=1; i<=n; i++){
            cin>>a>>b;scanf("%d",&w);
            if(mp.find(a)==mp.end()){
                u = (++val);
                mp[a] = val;
            }
            else u = mp[a];
            if(mp.find(b)==mp.end()){
                v = (++val);
                mp[b] = val;
            }
            else v = mp[b];
 
            node.push_back(Edge(u,v,w));
            node.push_back(Edge(v,u,w));
        }
        sort(node.begin(), node.end(),comp);
        int ans =kruskal(val,node.size());
        bool p = true;
        int pp = findPar(1);
        for(int i=2; i<=val; i++){
            if(findPar(i)!= pp){
                p = false;
                break;
            }
        }
        printf("Case %d: ",t);
        if(p==true)
            printf("%d\n",ans);
        else
            printf("Impossible\n");
        if(t!= tc){
            node.clear();
            mp.clear();
        }
 
    }
}