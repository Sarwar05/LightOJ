#include<bits/stdc++.h>
using namespace std;
int dirx[] =  {1,-1,0,0};
int diry[] =  {0,0,1,-1};
char grid[25][25];
int vis[25][25];
int bfs(int x, int y)
{
    queue<int> Q;
    vis[x][y]=0;
    Q.push(x);
    Q.push(y);
    while(! Q.empty()){
        int tx = Q.front();Q.pop();
        int ty = Q.front(); Q.pop();
        for(int i=0; i<=3; i++){
            int a = tx+dirx[i];
            int b = ty+diry[i];
            if(grid[a][b] == 'h'){
                return (vis[tx][ty]+1);
            }
            if((grid[a][b] != '#' && grid[a][b] !='m') && vis[a][b] == 0){
                vis[a][b] = vis[tx][ty]+1;
                Q.push(a);
                Q.push(b);
            }
        }
    }
}
int main()
{
    int tc, m ,n;
    scanf("%d",&tc);

    for(int t=1; t<=tc; t++){
        scanf("%d%d",&m,&n);

        int ax,ay,bx,by,cx,cy;

        for(int i=0; i<m; i++){
            scanf("%s",grid[i]);

            for(int j=0; j<n; j++){
                if(grid[i][j]=='a') ax=i,ay=j;
                if(grid[i][j]=='b') bx=i,by=j;
                if(grid[i][j]=='c') cx=i,cy=j;
            }

        }

        memset(vis,0,sizeof vis);
        int ans1=bfs(ax,ay);
        memset(vis,0,sizeof vis);
        int ans2=bfs(bx,by);
        memset(vis,0,sizeof vis);
        int ans3=bfs(cx,cy);
        int ans = max(ans1, max(ans2, ans3));

        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
