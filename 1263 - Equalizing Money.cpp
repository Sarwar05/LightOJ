#include<bits/stdc++.h>
using namespace std;
#define mx 1002
vector<int> adj[mx];
int money[mx];
int vis[mx];
set<int> avg;
bool bfs(int s)
{
    int amount  = 0;
    int cunt = 0;
    amount+=money[s];
    cunt++;
    vis[s] = 1;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        int sz = adj[x].size();
        for(int i=0; i<sz; i++){
            int u = adj[x][i];
            if(vis[u]==0){
                vis[u] = 1;
                amount+=money[u];
                cunt++;
                Q.push(u);
            }
        }
    }
    //cout<<"amount cunt "<<amount<<" "<<cunt<<endl;
    avg.insert(amount/cunt);
    return amount % cunt == 0? true : false;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc; scanf("%d",&tc);
    int n,m,a,u,v;
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++){
            scanf("%d",&money[i]);
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1; i<=n; i++)
            vis[i] = 0;
        bool res = true, temp;
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                temp = bfs(i);
                //cout<<"temp = "<<temp<<endl;
                //cout<<"set size: "<<avg.size()<<endl;
                if(temp==false || avg.size()!=1){
                    res = false;
                    //cout<<"breaking"<<endl;
                    break;
                }

            }
        }
        printf("Case %d: %s\n",t, res==true ? "Yes" : "No");

        if(t != tc){
            avg.clear();
            for(int i=1;i<=n; i++)
                adj[i].clear();
        }
    }
    return 0;
}
