#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int grid[15][15];
int vis[12][12];
int cost[12][12];
char str[12];
int dirx[] = {1,1,2,2,-1,-1,-2,-2};
int diry[] = {2,-2,1,-1,2,-2,1,-1};
void bfs(pii s)
{
    int rider = grid[s.first][s.second];
    int ride = 0;
    map<pii, int> mp;
    vis[s.first][s.second]++;
    mp[s]++;
    pii mns = make_pair(-100,-100);
    queue<pii> q;
    q.push(mns);
    q.push(s);
    while(!q.empty()){
        s = q.front();
        q.pop();
        if(s.first==-100 && s.second==-100){
            ride++;
            q.push(mns);
            if(q.size()==1) return;
            else continue;
        }
        vector<pii> v, v2;
        v.push_back(s);
        for(int j=1; j<=rider; j++){
            for(int k=0; k<(int)v.size(); k++){
                s = v[k];
                for(int i=0; i<8; i++){
                    int xx = s.first + dirx[i];
                    int yy = s.second + diry[i];
                    pii p = make_pair(xx,yy);
                    if(mp[p]==0 && grid[xx][yy] !=-1 &&xx>0 && yy>0){
                        mp[p]++;
                        vis[xx][yy]++;
                        cost[xx][yy] += ride;
                        v2.push_back(p);
                        q.push(p);
                    }
                }
            }
            v = v2;v2.clear();
        }
    }
}
int main()
{
    int tc, cs = 0, n,m,a;
    scanf("%d", &tc);
    while(tc--){
        memset(grid, -1, sizeof grid);
        memset(vis, 0, sizeof vis);
        memset(cost, 0, sizeof cost);
        vector<pii>v;
        scanf("%d%d",&m, &n);
        for(int i=1; i<=m; i++){
            scanf("%s", str);
            for(int j=0; j<n; j++){
                if(str[j]=='.'){
                    a=0;
                }
                else{
                    v.push_back(make_pair(i,j+1));
                    a = str[j]-'0';
                }
                grid[i][j+1] = a;
            }
        }
        int sz = v.size();
        for(int i=0; i<sz; i++) bfs(v[i]);
        int ans = 100000000;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(vis[i][j]==sz){
                    ans = min(ans, cost[i][j]);
                }
            }
        }
        if(ans == 100000000) ans = -1;
        printf("Case %d: %d\n", ++cs, ans);
    }
    return 0;
}
