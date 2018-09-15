
#include<bits/stdc++.h>
using namespace std;
#define mx  20002
#define vi vector<int>
vi adj[mx];
vi trans[mx];
int vis[mx], compo[mx], in[mx], out[mx], scc;
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
    for(int i=0; i<trans[s].size(); i++){
        int u = trans[s][i];
        if(vis[u]==0){
            vis[u] = 1;
            dfs2(u);
        }
    }
    compo[s] = scc;
}
int main()
{

    //freopen("out.txt","w",stdout);
    int tc,n,m,a,b;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&m);

        for(int i=1; i<=m; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            trans[b].push_back(a);
        }
        scc = 0;
        memset(vis, 0, sizeof vis);
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                vis[i]=1;
                dfs1(i);
            }
        }
        memset(vis, 0, sizeof vis);
        while(!st.empty()){
            int u = st.top();
            st.pop();
            if(vis[u]==0){
                vis[u] = 1;
                scc++;
                dfs2(u);
            }
        }

        int ans;
        if(scc==1) ans = 0;
        else{
            memset(in, 0, sizeof in);
            memset(out,0,sizeof out);
            for(int i=1; i<=n; i++){
                for(int j=0; j<adj[i].size(); j++){
                    int u = adj[i][j];
                    if(compo[i]!= compo[u]){
                        in[ compo[u] ]++;
                        out[ compo[i] ]++;
                    }
                }
            }
            int con1=0,con2=0;
            for(int i=1; i<=scc; i++){
                if(in[i]==0)con1 ++;
                if(out[i]==0)con2 ++;
            }
            ans = max(con1,con2);
        }

        printf("Case %d: %d\n",t,ans);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            trans[i].clear();
        }
    }

    return 0;
}
