#include<bits/stdc++.h>
using namespace std;
#define mx 10005
typedef vector<int> vi;
vi adj[mx];
int vis [mx];
int out[mx];
int in[mx];
struct Node
{
    int x;
    int outd;
    int ind;
    Node(int a, int b,int c){
        x = a;
        outd = b;
        ind = c;
    }
};
bool compout(Node a, Node b)
{
    return a.outd > b.outd;
}
bool compin(Node a, Node b)
{
    return a.ind < b.ind;
}
void dfs(int s)
{
    vis[s] = 1;
    for(int i=0; i<adj[s].size(); i++){
        if(vis[adj[s][i] ]==-1){
            dfs(adj[s][i]);
        }
    }
}
int main()
{
    int tc,n,m,a,b,ans;
    scanf("%d",&tc);
    for(int t=1; t<=tc ;t++){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++){
            vis[i] = -1;
            out[i] = 0;
            in[i] = 0;
        }

        for(int i=1; i<=m; i++){
            scanf("%d%d",&a, &b);
            adj[a].push_back(b);
            out[a]++;
            in[b]++;
        }
        vector<Node > v;
        for(int i=1; i<=n; i++){
            v.push_back(Node(i, out[i], in[i]));
        }
        sort(v.begin(), v.end(),compout);
        ans = 0;
        for(int i=0; i<n; i++){
            int s =v[i].x;
            if(vis[s]==-1){
                dfs(s);
                ans++;
            }
        }
        for(int i=1; i<=n; i++){
            vis[i] = -1;
        }
        int tem=0;
        sort(v.begin(), v.end(),compin);
        for(int i=0; i<n; i++){
            int s =v[i].x;
            if(vis[s]==-1){
                dfs(s);
                tem++;
            }
        }
        ans = min(ans, tem);
        printf("Case %d: %d\n",t,ans);
        for(int i=1; i<=n; i++) adj[i].clear();
    }
}
