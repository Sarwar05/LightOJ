#include<bits/stdc++.h>
using namespace std;
#define ll int
#define inf 1e8
#define vi vector<int>
struct Edge
{
    int from;
    int to;
    ll cap;
    ll flow = 0;
    int a;
    Edge(int _from, int _to, ll _cap, int _a)
    {
        from = _from;
        to = _to;
        cap = _cap;
        a = _a;
    }
};
struct Dinic
{
    vector<Edge> edges;
    vector<vi> adj;
    int n, m=0;
    int source,sink;
    vi level, ptr;
    queue<int> q;
    Dinic(int _n, int _source, int _sink)
    {
        n = _n+5;
        source = _source;
        sink = _sink;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void addEdge(int from, int to, ll cap, int a)
    {
        //cout<<"add: "<<from<<" "<<to<<" "<<cap<<" "<<a<<endl;
        edges.push_back(Edge(from, to, cap,a));
        adj[from].push_back(m++);
        edges.push_back(Edge(to, from, 0,-1));
        adj[to].push_back(m++);
    }
    bool bfs()
    {
        while(!q.empty()){
            int from = q.front();
            q.pop();
            for(int i=0; i<adj[from].size(); i++){
                int id = adj[from][i];
                int to = edges[id].to;
                if(edges[id].cap - edges[id].flow ==0)
                    continue;
                if(level[ to ] != -1) continue;
                level[to] = level[from] + 1;
                q.push(to);
            }
        }
        return level[sink] != -1;
    }
    ll dfs(int from, ll pushed)
    {
        if(pushed==0) return 0;
        if(from==sink) return pushed;
        for(int& cid = ptr[from]; cid<(int)adj[from].size(); cid++){
            int id = adj[from][cid];
            int to = edges[id].to;
            if(level[from]+1 != level[to] || edges[id].cap - edges[id].flow == 0)
                continue;
            ll tempFlow = dfs(to, min(pushed, edges[id].cap - edges[id].flow));
            if(tempFlow==0) continue;
            edges[id].flow +=tempFlow;
            edges[id^1].flow -=tempFlow;
            return tempFlow;
        }
        return 0;
    }
    ll getFlow()
    {
        for(int i=0; i<m; i++) edges[i].flow = 0;
        ll maxFlow = 0;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[source] = 0;
            while(!q.empty()) q.pop();
            q.push(source);
            if(bfs()==false) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(source, inf))
                maxFlow+=pushed;
        }
        //cout<<"maxFlow: "<<maxFlow<<endl;
        return maxFlow;
    }
};
#define mx 52
int mat[mx][mx], used[mx*mx], ray1[mx*2], ray2[mx*2];
pair<int, int> anti[mx*mx];
int main()
{
    int tc, cs=1, r,c;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d", &r,&c);
        int val = 0;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                mat[i][j] = ++val;
                anti[val] = make_pair(i,j);
            }
        }
        int n = r+c-1;
        Dinic dinic(n + n + 2, 0, n + n + 1);
        vector<int> cross1[n+1], cross2[n+1];
        /**
        generate cross
        */
        int id = 1,x, p;
        memset(used, 0, sizeof used);
        for(int i=1,x=1; x<=r; i+=c, x++, id++){
            int now = i;
            p = i;
            vector<int> v;
            while(now>0 && used[now]==0){
                used[now] = 1;
                v.push_back(now);
                now-=(c-1);
            }
            cross1[id] = v;
        }
        for(int i = p+1; i<=r*c; i++, id++){
            int now = i;
            vector<int> v;
            while(now>0 && used[now]==0){
                used[now] = 1;
                v.push_back(now);
                now-=(c-1);
            }
            cross1[id] = v;
        }
        /// //////////////////////
        id = 1;
        memset(used, 0, sizeof used);
        for(int i=c,x=1; x<=r; i+=c, x++, id++){
            int now = i;
            p = i;
            vector<int> v;
            while(now>0 && used[now]==0){
                used[now] = 1;
                v.push_back(now);
                now-=(c+1);
            }
            cross2[id] = v;
        }
        //cout<<"ok"<<endl;
        for(int i = p-1; used[i]==0 && i>0; i--, id++){
            int now = i;
            vector<int> v;
            while(now>0 && used[now]==0){
                used[now] = 1;
                v.push_back(now);
                now-=(c+1);
            }
            cross2[id] = v;
        }

//        for(int i=1; i<=n; i++){
//            for(int j=0; j<cross2[i].size(); j++){
//                cout<<cross2[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        /// //////////////////////////////////////
        for(int i=1; i<=n; i++){
            scanf("%d", &ray1[i]);
            dinic.addEdge(0, i, ray1[i] - (int)cross1[i].size(), -1);
        }
        for(int i=1; i<=n; i++){
            scanf("%d", &ray2[i]);
            dinic.addEdge(n+i, n+n+1, ray2[i] - (int)cross2[i].size(), -1);
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k1 = 0; k1<cross1[i].size(); k1++){
                    for(int k2 = 0; k2<cross2[j].size(); k2++){
                        int a = cross1[i][k1];
                        int b = cross2[j][k2];
                        if(a==b)
                            dinic.addEdge(i, n+j, 99, a);
                    }
                }
            }
        }
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++)
                mat[i][j] = 1;
        }
        dinic.getFlow();
        for(int i=0; i<dinic.m; i++){
            int a = dinic.edges[i].a;
            if(a != -1){
            //cout<<a<<" "<<dinic.edges[i].flow<<endl;
                mat[anti[a].first][anti[a].second]+=dinic.edges[i].flow;
            }
        }
        printf("Case %d:\n", cs++);
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                printf("%d", mat[i][j]);
                if(j==c) printf("\n");
                else printf(" ");
            }
        }
    }
}
