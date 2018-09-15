#include<bits/stdc++.h>
using namespace std;
#define mx 5005
vector< bitset<mx> >reachable(mx) ;
int finish[mx];
bool comp(const int a,const int b)
{
    return finish[a]>finish[b];
}
vector<int> adj[mx];
int Time;
int vis[mx];
stack<int> st;
void dfs1(int u)
{
    vis[u] = 1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(vis[v]==0){
            dfs1(v);
        }
        reachable[u]|=reachable[v];
    }
    st.push(u);
}
void dfs2(int u)
{
    vis[u] = 1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(vis[v]==0){
            dfs2(v);
        }
    }
    finish[u] = ++Time;
}
int main()
{
    int tc,cs=1,n,m,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) {
            adj[i].clear();
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }
        while(!st.empty()) st.pop();
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                reachable[i][j] = 0;
        for(int i=1; i<=n; i++){
            vis[i] = 0;
            reachable[i][i] = 1;
        }
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                dfs1(i);
            }
        }
        Time = 0;
        for(int i=1; i<=n; i++)vis[i] = 0;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(vis[x]==0)dfs2(x);
        }
        vector< pair<int,int> >ans;
        for(int i=1; i<=n; i++){
            sort(adj[i].begin(), adj[i].end(), comp);
            bitset<mx> visit;
            for(int j=0; j<adj[i].size(); j++){
                int v = adj[i][j];
                if(visit[v]==0){
                    ans.push_back({i,v});
                }
                visit |= reachable[v];
            }
        }
        sort(ans.begin(),ans.end());
        printf("Case %d: %d\n",cs++,ans.size());
        for(int i=0; i<ans.size(); i++){
            printf("%d %d\n",ans[i].first, ans[i].second);
        }
    }
    return 0;
}