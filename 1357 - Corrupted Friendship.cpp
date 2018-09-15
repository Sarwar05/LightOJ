#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int> adj[mx];
int child[mx], vis[mx];
int invite, trav;
int card;
long long ans;
void dfs(int s)
{
    vis[s] = 1;
    for(int i=0; i<adj[s].size(); i++){
        int v = adj[s][i];
        if(vis[v]==0&&card>0){
            invite++;
            card--;
            dfs(v);
        }
    }
}

void dfs3(int s)
{
    trav++;
    vis[s] = 1;
    int cnt = 0;
    vector<int> v;
    for(int i=0; i<adj[s].size(); i++){
        int u = adj[s][i];
        if(vis[u]==0){
            dfs3(u);
            cnt+=child[u];
            v.push_back(child[u]);
        }
    }
    child[s]+=cnt;
    int sz = v.size();
    if(sz>1){
        long long tem = 0;
        vector<int> cum(sz);
        cum[sz-1] = v[sz-1];
        for(int i=sz-2; i>=0; i--){
            cum[i] = cum[i+1] + v[i];
        }
        for(int i=0; i<sz-1; i++){
            tem = tem + (v[i] * cum[i+1]);
        }
        ans+=tem;
    }
}

int main()
{
    int tc, cs=1, n, a,b;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i=1; i<n; i++){
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
        }
        invite = 0;
        for(int i=1; i<=n; i++){
            vis[i] = 0;
        }
        card = n;
        dfs(1);
        for(int i=1; i<=n; i++){
            vis[i] = 0;
            child[i] = 1;
        }
        ans = 0;
        trav = 0;
        dfs3(1);
        int nt = n - trav;
        ans = ans +  nt * (n-nt);
        printf("Case %d: %d %lld\n", cs++, invite, ans);
    }
    return 0;
}

