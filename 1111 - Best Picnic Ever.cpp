#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1002];
int possib[1002];
int vis[1002];
void bfs(int s)
{
    vis[s] = 1;
    possib[s]++;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        int sz = adj[a].size();
        for(int i=0; i<sz; i++){
            int x = adj[a][i];
            if(vis[x]==0){
                Q.push(x);
                vis[x]=1;
                possib[x]++;
            }
        }
    }
}
int main()
{
    int tc,k,n,m,a,b;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d%d",&k,&n,&m);
        int pos[k];
        for(int i=0; i<k; i++)
            scanf("%d",&pos[i]);
        for(int i=1; i<=m;i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }
        for(int i=0; i<=n;i++)possib[i]=0;
        for(int j=0; j<k; j++){
            for(int i=0; i<=n;i++)vis[i]=0;
            bfs(pos[j]);
        }
        int ans = 0;
        for(int i=0; i<=n; i++) if(possib[i]==k)ans++;
        printf("Case %d: %d\n",t,ans);
        for(int i=1; i<=n; i++)
            adj[i].clear();
    }
    return 0;
}
