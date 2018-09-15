#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define vi vector<int>
vi adj[mx],rev[mx];
int vis[mx],in[mx], out[mx], comp[mx],scc;
stack<int> st;
void dfs1(int s)
{
    for(int i=0; i<adj[s].size(); i++){
        int u = adj[s][i];
        if(vis[u]==0){
            vis[u] = 1;
            dfs1(u);
        }
    }
    st.push(s);
}
void dfs2(int s)
{
    for(int i=0; i<rev[s].size(); i++){
        int u = rev[s][i];
        if(vis[u]==0){
            vis[u] = 1;
            dfs2(u);
        }
    }
    comp[s] = scc;
}
int main()
{
    int tc,n,k,u,v;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        set<int> se;
        for(int i=1; i<=n; i++){
            scanf("%d",&k);
            for(int j=1; j<=k; j++){
                scanf("%d%d",&u,&v);
                adj[u].push_back(v);
                rev[v].push_back(u);
                se.insert(u);
                se.insert(v);
            }
        }
        memset(vis, 0, sizeof vis);
        vis[0] = 1;
        dfs1(0);
        memset(vis, 0, sizeof vis);
        scc=0;for(int i=0; i<mx; i++) comp[i] = 1000000;
        int tem1 = st.size();
        while(!st.empty()){
            int u = st.top();
            st.pop();
            if(vis[u]==0){
                vis[u] = 1;
                dfs2(u);
                scc++;
            }
        }
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);

        for(int i=0; i<mx; i++){
            for(int j=0; j<adj[i].size(); j++){
                int u = adj[i][j];
                if(comp[i] != comp[u]){
                    in[ comp[u] ]++;
                    out[ comp[i] ]++;
                }
            }
        }
        bool ans = true;
        for(int i=0; i<scc; i++){
            if(out[i]>=2){
                ans = false;
                break;
            }
        }
        if(tem1!= se.size()) ans = false;
        printf("Case %d: %s\n",t,ans==true ? "YES" : "NO");
        for(int i=0; i<mx; i++){
            adj[i].clear();
            rev[i].clear();
        }

    }
    return 0;
}
