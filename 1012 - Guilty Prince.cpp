#include<bits/stdc++.h>
using namespace std;
int dirx[] = {1,-1,0,0};
int diry[] = {0,0,1,-1};
char str[22][22];
int vis[22][22];
int r,c;
int bfs(int x, int y)
{
    int ans = 1;
    vis[x][y] = 1;
    queue<int> Q;
    Q.push(x);Q.push(y);
    while(!Q.empty()){
        int x1 = Q.front();Q.pop();
        int y1 = Q.front(); Q.pop();
        for(int i=0; i<=3; i++){
            int tx = x1+dirx[i];
            int ty = y1+diry[i];
            if(tx>=0 && tx<r && ty>=0 && ty<c){
                if(vis[tx][ty]==0 && str[tx][ty] != '#'){
                    vis[tx][ty] = 1;
                    ans++;
                    Q.push(tx);
                    Q.push(ty);
                }
            }
        }
    }
    return ans;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        memset(vis, 0, sizeof vis);
        scanf("%d%d",&c,&r);
        int x=-1,y=-1;
        for(int i=0; i<r; i++){
            scanf("%s",str[i]);
            for(int j = strlen(str[i])-1; j>=0 && x<0; j--){
                if(str[i][j]=='@'){
                    x = i,y=j;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",t,bfs(x,y));
    }
    return 0;
}
