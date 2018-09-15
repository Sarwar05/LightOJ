#include<bits/stdc++.h>
using namespace std;
int dirx[] =  {1,-1,0,0};
int diry[] =  {0,0,1,-1};
char grid[501][501];
int vis[501][501];
int dp[501][501];
int m,n;
struct pos
{
    int x;
    int y;
    pos(int a, int b){
        x = a;
        y = b;
    }
};
int bfs(int x, int y)
{
    int ret = 0;
    queue<int> Q;
    vector<pos> pv;
    pv.push_back(pos(x,y));
    vis[x][y]=0;
    Q.push(x);
    Q.push(y);
    while(! Q.empty()){
        int tx = Q.front();Q.pop();
        int ty = Q.front(); Q.pop();
        for(int i=0; i<=3; i++){
            int a = tx+dirx[i];
            int b = ty+diry[i];
            if(a>=0 && a<m && b>=0 && b<n){
                if(grid[a][b] != '#'  && vis[a][b] == 0){
                    //cout<<"going to-> "<<a<<" "<<b<<endl;
                    if(grid[a][b]=='C')
                        ret++;
                    pv.push_back(pos(a,b));
                    vis[a][b] = 1;
                    Q.push(a);
                    Q.push(b);
                }
            }
        }
    }
    int sz = pv.size();
    for(int i=0; i<sz; i++){
        dp[pv[i].x][pv[i].y] = ret;
    }
    return ret;
}
int main()
{
    int tc,q,a,b;
    scanf("%d",&tc);

    for(int t=1; t<=tc; t++){
        memset(dp, -1, sizeof dp);
        scanf("%d%d%d",&m,&n,&q);
        for(int i=0; i<m; i++)
            scanf("%s",grid[i]);
        printf("Case %d:\n",t);
        while(q--){
            scanf("%d%d",&a,&b);
            if(dp[a-1][b-1] != -1){
                printf("%d\n",dp[a-1][b-1]);
            }
            else{
                memset(vis,0,sizeof vis);
                printf("%d\n",bfs(a-1,b-1));
            }

        }

    }
    return 0;
}
