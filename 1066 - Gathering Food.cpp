#include<bits/stdc++.h>
using namespace std;
struct pos
{
    char ch;
    int x;
    int y;
    pos(char c,int a, int b)
    {
        ch = c;
        x = a;
        y = b;
    }
};
bool operator < (pos a, pos b)
{
    return a.ch < b.ch;
}
vector<pos> pv;
int dirx[] =  {1,-1,0,0};
int diry[] =  {0,0,1,-1};
char grid[12][12];
int vis[12][12];
int bfs(int x, int y, int f, int g,int n)
{
    queue<int> Q;
    grid[x][y] = '.';
    vis[x][y]=0;
    Q.push(x);
    Q.push(y);
    while(! Q.empty()){
        int tx = Q.front();Q.pop();
        int ty = Q.front(); Q.pop();
        for(int i=0; i<=3; i++){
            int a = tx+dirx[i];
            int b = ty+diry[i];
            if(a==f && b==g){
                return (vis[tx][ty]+1);
            }
            if((a>=0 && a<n && b>=0 && b<n) && (grid[a][b] =='.' && vis[a][b] == 0)){
                vis[a][b] = vis[tx][ty]+1;
                Q.push(a);
                Q.push(b);
            }
        }
    }
    return -1;
}
int main()
{
    int tc, m ,n;
    scanf("%d",&tc);

    for(int t=1; t<=tc; t++){
        scanf("%d",&n);

        int ax,ay,bx,by,cx,cy;

        for(int i=0; i<n; i++){
            scanf("%s",grid[i]);

            for(int j=0; j<n; j++){
                if(isalpha(grid[i][j])){
                    pv.push_back(pos(grid[i][j],i,j));
                }
            }
        }
        sort(pv.begin(), pv.end());
        int ans = 0;int sz = pv.size();
        for(int i=0; i<sz-1; i++){
            memset(vis,0,sizeof vis);
            int tem = bfs(pv[i].x,pv[i].y, pv[i+1].x, pv[i+1].y,n);
            if(tem==-1){
                ans = -1;
                break;
            }
            ans+=tem;
        }
        if(ans != -1)
            printf("Case %d: %d\n",t,ans);
        else
            printf("Case %d: Impossible\n",t);
        pv.clear();
    }
    return 0;
}
