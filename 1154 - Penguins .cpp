#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX/2
#define mx 202
#define pb push_back
double x[102], y[102];
vector<int> adj[mx];
int cap[mx][mx];
int passed[mx][mx];
int par[mx];
bool bfs(int source, int sink)
{
    memset(par,-1,sizeof par);
    par[source] = -2;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0 ;i<adj[u].size(); i++){
            int v = adj[u][i];
            if(par[v]==-1 && cap[u][v] - passed[u][v] >0){
                par[v] = u;
                if(v==sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int findMaxFlow(int source, int sink)
{
    int maxFlow = 0, flow;
    while(bfs(source,sink)){
        flow = inf;
        int prev, now = sink;
        while(now!=source){
            prev = par[now];
            flow = min(flow, cap[prev][now] - passed[prev][now]);
            now = prev;
        }
        maxFlow+=flow;
        now = sink;
        while(now!=source){
            prev = par[now];
            passed[prev][now]+=flow;
            passed[now][prev]-=flow;
            now = prev;
        }
    }
    return maxFlow;
}
int main()
{
    int tc,cs=1,a,b,n,total;
    double d;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<mx; i++) adj[i].clear();
        memset(cap, 0, sizeof cap);
        scanf("%d%lf",&n,&d);
        total = 0;
        for(int i=1; i<=n; i++){
            scanf("%lf%lf%d%d",&x[i],&y[i],&a,&b);
            total+=a;
            cap[0][i] = a;
            cap[i][100+i] = b;
            adj[i].push_back(100+i);
            adj[100+i].push_back(i);
            adj[0].push_back(i);
            adj[i].push_back(0);
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                double dist = sqrt(pow(x[i]-x[j] ,2) + pow( y[i]-y[j] ,2));
                if(dist<=d){
                    cap[100+i][j] = inf;
                    cap[100+j][i] = inf;
                    adj[i].push_back(100+j);
                    adj[100+j].push_back(i);
                    adj[100+i].push_back(j);
                    adj[j].push_back(100+i);
                }
            }
        }
        printf("Case %d:",cs++);
        vector<int> ans;
        for(int i=1; i<=n;i++){
            memset(passed,0,sizeof passed);
            if(findMaxFlow(0,i) == total) ans.pb(i);
        }
        if(ans.size()==0) printf(" -1");
        else{
            for(int i=0; i<ans.size(); i++){
                printf(" %d",ans[i]-1);
            }
        }
        printf("\n");
    }
    return 0;
}
