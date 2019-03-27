///
#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define pii pair<int, int>
pii get(int a, int b)
{
    return { min(a,b), max(a,b) };
}
vector<int> adj[mx];
int ids[mx], low[mx], vis[mx], Time;
set<pii> bridges;
void dfs(int u, int p)
{
	vis[u] = 1;
	low[u] = ids[u] = ++Time;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v==p) continue;
		if(vis[v])
			low[u]= min(low[u], ids[v]);
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(ids[u] < low[v]){
				bridges.insert(get(u,v));
			}
		}
	}
}
void findBridges(int n)
{
	bridges.clear();
	Time = 0;
	for(int i=0; i<n; i++){
		if(vis[i]==0)
			dfs(i, -1);
	}
}
int cnt, colorOk;
void bicolor(int u, int color)
{
    if(color>2) color = 1;
    cnt++;
    vis[u] = color;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(bridges.count(get(u,v))) continue;
        if(vis[v]==0){
            bicolor(v,color+1);
        }
        else{
            if(vis[u]==vis[v]) colorOk = 0;
            else;
        }
    }
}
int main()
{
    int tc,n,a,b,cs=1,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d", &n,&m);
        for(int i=0; i<n; i++) adj[i].clear(), vis[i] = 0;
        while(m--){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        findBridges(n);
        int ans = 0;
        memset(vis, 0, sizeof vis);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                cnt = 0, colorOk = 1;
                bicolor(i,1);
                if(colorOk==0)
                    ans+=cnt;
            }
        }
        printf("Case %d: %d\n", cs++, ans);
    }
}
