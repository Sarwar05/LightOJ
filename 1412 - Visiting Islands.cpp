#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define pii pair<int,int>
#define inf 10000007
vector<int> adj[mx];
int vis[mx],dist[mx];
vector<int> v;
pii bfs(int s)
{
    int node=s,cost=0;
    dist[s] = 0;
    vis[s] = 1;
    v.push_back(s);
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            s = adj[u][i];
            if(vis[s]==0){
                v.push_back(s);
                dist[s] = dist[u] + 1;
                vis[s] = 1;
                q.push(s);
                if(dist[s]>cost){
                    cost = dist[s];
                    node = s;
                }
            }
        }
    }
    return {node,cost};
}
struct Info
{
    int total;
    int diam;
    Info(int _total, int _diam)
    {
        total = _total;
        diam = _diam;
    }
    bool operator<(const Info& ob) const
    {
        if(total==ob.total) return diam>ob.diam;
        return total>ob.total;
    }
};
vector<Info> info;
int main()
{
    int tc,cs=1,n,m,a,b,q,k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) adj[i].clear();
        memset(vis,0,sizeof vis);
        info.clear();
        for(int i=1; i<=m; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                v.clear();
                pii xxx = bfs(i);
                for(int j=0; j<v.size(); j++) vis[ v[j] ] = 0;
                v.clear();
                xxx = bfs(xxx.first);
                info.push_back(Info(v.size(),xxx.second+1));
            }
        }
        sort(info.begin(),info.end());
        //for(int i=0; i<info.size(); i++) cout<<"in "<<info[i].total<<" "<<info[i].diam<<endl;
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d",&k);
            int ans = inf;
            for(int i=0; i<info.size(); i++){
                if(info[i].total<k) break;
                else if(info[i].diam >= k){
                    ans = k-1;
                    break;
                }
                else{
                    int tem = info[i].diam;
                    tem+=((k-tem)*2);
                    ans = min(ans,tem-1);
                }
            }
            if(ans==inf) printf("impossible\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
/**
2
2 1
1 2
3
1
2
3
5 4
1 2
2 3
2 4
2 5
2
3
2
*/
