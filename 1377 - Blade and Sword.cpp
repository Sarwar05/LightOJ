#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define ff first
#define ss second
#define inf 1000000000
char grid[202][202];
int dirx[] = {1,0,-1,0};
int diry[] = {0,1,0,-1};
int bfs(pii s, pii t)
{
    int ret = 0;
    map<pii, int> vis;
    vis[s] = 1;
    queue<pii> q, q2;
    q.push(s);
    while(!q.empty()){
        ret++;
        while(!q.empty()){
            s = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int xx = s.ff + dirx[i];
                int yy = s.ss + diry[i];
                if(grid[xx][yy]!='#' && grid[xx][yy]!='*'){
                    pii u = make_pair(xx,yy);
                    if(vis.find(u)==vis.end()){
                        if(u==t) return ret;
                        vis[u] = 1;
                        q2.push(u);
                    }
                }
            }
        }
        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
    }
    return inf;
}
piii tele(pii s)
{
    int ret = 0;
    map<pii, int> vis;
    vis[s] = 1;
    queue<pii> q, q2;
    q.push(s);
    while(!q.empty()){
        ret++;
        while(!q.empty()){
            s = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int xx = s.ff + dirx[i];
                int yy = s.ss + diry[i];
                if(grid[xx][yy]!='#'){
                    pii u = make_pair(xx,yy);
                    if(vis.find(u)==vis.end()){
                        if(grid[xx][yy]=='*') return make_pair(ret, u);
                        vis[u] = 1;
                        q2.push(u);
                    }
                }
            }
        }
        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
    }
    return make_pair(inf, make_pair(-1,-1));
}
pii tele2(pii s,pii fb)
{
    int ret = 0;
    map<pii, int> vis;
    vis[s] = 1;
    vis[fb] = 1;
    queue<pii> q, q2;
    q.push(s);
    int found = -1;
    while(!q.empty()){
        ret++;
        while(!q.empty()){
            s = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int xx = s.ff + dirx[i];
                int yy = s.ss + diry[i];
                if(grid[xx][yy]!='#'){
                    pii u = make_pair(xx,yy);
                    if(u==fb) found = ret;
                    if(vis.find(u)==vis.end()){
                        if(grid[xx][yy]=='*') return make_pair(ret,found);
                        vis[u] = 1;
                        q2.push(u);
                    }
                }
            }
        }
        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
    }
    return make_pair(inf, found);
}
int main()
{
    int tc, cs=1;
    int n,m;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d", &m, &n);
        pii p,d;
        int star = 0;
        for(int i=0; i<m; i++){
            scanf("%s",grid[i]);
            for(int j=0; j<n; j++){
                if(grid[i][j]=='P'){
                    p = make_pair(i,j);
                }
                if(grid[i][j]=='D'){
                    d = make_pair(i,j);
                }
                if(grid[i][j]=='*'){
                    star++;
                }
            }
        }
        printf("Case %d: ", cs++);
        int ans = bfs(p,d);
        piii x = tele(p);
        int ans2 = x.ff;
        if(ans2!=inf){
            pii ret = tele2(d,x.ss);
            int tem = ret.ff;
            if(tem==inf){
                ans2 = inf;
            }
            else
                ans2 = ans2 + tem + 1;
            if(ret.ss != -1 && star>1){
                //cout<<"first"<<endl;
                ans2 = min(ans2, x.ff + ret.ss + 2);
            }
        }
        x = tele(d);
        int ans3 = x.ff;
        if(ans3!=inf){
            pii ret = tele2(p,x.ss);
            int tem = ret.ff;
            if(tem==inf)
                ans3 = inf;
            else
                ans3 = ans3 + tem + 1;
            if(ret.ss!=-1 && star>1){
                //cout<<"second"<<endl;
                ans3 = min(ans3, x.ff + ret.ss + 2);
            }
        }
        //cout<<"ans: "<<ans<<" "<<ans2<<" "<<ans3<<endl;
        ans2 = min(ans2, ans3);
        ans = min(ans, ans2);
        if(ans==inf)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
/**
##########
#...P*D..#
##########

##########
#*..P*D..#
##########
*/

