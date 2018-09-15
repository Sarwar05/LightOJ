#include<bits/stdc++.h>
using namespace std;
#define mx 50003
typedef vector<int> vi;
vi adj[mx], trans[mx];
int vis[mx];//, vis2[mx];
vi ret;
stack<int > st;
void dfs(int s)
{
    for(int i=0; i<adj[s].size(); i++){
        int u = adj[s][i];
        if(vis[u]==0){
            vis[u] = 1;
            dfs(u);
        }
    }
    ret.push_back(s);
}
void finishTime(int s)
{
    for(int i=0; i<adj[s].size(); i++){
        int u = adj[s][i];
        if(vis[u]==0){
            vis[u] = 1;
            finishTime(u);
        }
    }
    st.push(s);
}
void visitReverse(int s)
{
    for(int i=0; i<trans[s].size(); i++){
        int u = trans[s][i];
        if(vis[u]==0){
            vis[u] = 1;
            visitReverse(u);
        }
    }
    ret.push_back(s);
}
vi findSCC(int n)
{
    vi res;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            vis[i]==1;
            finishTime(i);
        }
    }
    for(int i=1; i<=n; i++) vis[i] = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(vis[u]==1) continue;
        ret.clear();
        vis[u] = 1;
        visitReverse(u);
        sort(ret.begin(), ret.end());
        res.push_back(ret[0]);
    }
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    int tc,a,b,n;scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a, &b);
            adj[a].push_back(b);
            trans[b].push_back(a);
            vis[i] = 0;
            ///vis2[i] = 0;
        }
        int ans = 0, len = 0;
        vi scc = findSCC(n);
        //cout<<"total scc "<<scc.size()<<endl;
        for(int i=1; i<=n; i++) vis[i] = 0;
        for(int i=0; i<scc.size(); i++){
            //cout<<"visiting from "<<scc[i]<<endl;
            ret.clear();
            vis[scc[i]] = 1;
            dfs(scc[i]);
            if(ret.size()>len){
                len = ret.size();
                ans = scc[i];
            }
            for(int j=0; j<ret.size(); j++)
                vis[ ret[j] ] = 0;
        }
        printf("Case %d: %d\n",t,ans);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            trans[i].clear();
        }
        while(!st.empty())
            st.pop();
    }
    return 0;
}
