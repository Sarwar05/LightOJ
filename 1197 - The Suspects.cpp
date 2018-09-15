#include<bits/stdc++.h>
using namespace std;
#define mx 30005
vector<int> adj[mx];
int ans;
int vis[mx];
void dfs(int s=0)
{
    ans++;
    vis[s] = 1;
    for(int i=0; i<adj[s].size(); i++){
        int v = adj[s][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
}
int main()
{
    int n,m,a,x;
    while(cin>>n>>m){
        if((n|m)==0) return 0;
        memset(vis, 0, sizeof vis);
        for(int i=0; i<n; i++) adj[i].clear();
        while(m--){
            vector<int>v;
            cin>>x;
            while(x--){
                cin>>a;
                v.push_back(a);
            }
            for(int i=0; i<v.size(); i++){
                int a = v[i];
                for(int j=i+1; j<v.size(); j++){
                    int b  = v[j];
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }
        }
        ans = 0;
        dfs();
        cout<<ans<<endl;
    }
    return 0;
}
