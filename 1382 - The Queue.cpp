#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mx 1002
int dp[mx][mx];
vector<int> adj[mx];
int child[mx];
ll way[mx];
ll nCr(int n, int r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r];
    return dp[n][r] = (nCr(n-1,r) + nCr(n-1, r-1))%mod;
}
void dfs(int u)
{
    int cld = 0;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        dfs(v);
        cld+=child[v];
    }
    child[u] = ++cld;
    way[u] = 1;
    int total = child[u]-1;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        way[u]*=(nCr(total,child[v]));
        /**
        from total nodes, child[v] nodes has no dependency with (total-child[v]) nodes
        now we need to put child[v] nodes in all possible position inside (total-child[v])
        thinking a while you can figure out that...
        nCr(total,child[v]) means how many way we can choose child[v] positions in total slot
        */
        way[u]%=mod;
        way[u]*=way[v];
        way[u]%=mod;
        total-=child[v];
    }
}
int main()
{
    memset(dp, -1, sizeof dp);
    int tc,n,a,b,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        set<int> root;
        for(int i=1; i<=n; i++){
            adj[i].clear();
            root.insert(i);
            child[i] = 0;
        }
        for(int i=1; i<n; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            if(root.count(b)) root.erase(b);
        }
        dfs(*(root.begin()));
        printf("Case %d: %d\n", cs++,way[*(root.begin())]);
    }
}
