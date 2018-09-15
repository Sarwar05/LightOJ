#include<bits/stdc++.h>
using namespace std;
vector<int> adj[20001];
int vis[20001];
int bfs(int s)
{
    vis[s] = 9;
    int red=0,black=1;/// red=5,black=9
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        int sz = adj[u].size();
        for(int i=0; i<sz; i++){
            int v = adj[u][i];
            if(vis[v]==0){
                if(vis[u]==5){
                    vis[v] = 9;
                    black++;
                }
                else{
                    vis[v]=5;
                    red++;
                }
                Q.push(v);
            }
        }
    }
    return max(red, black);
}
int main()
{
    int tc,mx,mn,n,a,b;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        mx=-1,mn=100000;
        memset(vis,-1,sizeof vis);
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            mx = max(mx,max(a,b));
            mn = min(mn,min(a,b));
            vis[a]=vis[b] = 0;
        }
        int ans = 0;
        for(int i=mn; i<=mx; i++){
            if(vis[i]==0){
                ans+=bfs(i);
            }
        }
        printf("Case %d: %d\n",t,ans);

        if(t!=tc){
            for(int i=mn; i<=mx; i++)
                adj[i].clear();
        }
    }

    return 0;
}
