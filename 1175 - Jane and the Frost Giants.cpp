#include<bits/stdc++.h>
using namespace std;
int grid[205][205];
char str[205];
int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0 ,0};
queue<int> jena, fire;
int bfs()
{
    int ret = 0;
    int tx, ty,x,y;
    while(!jena.empty())
    {
        ret++;
        queue<int>p,q;
        while(!jena.empty())
        {
            tx = jena.front();
            jena.pop();
            ty = jena.front();
            jena.pop();
            if(grid[tx][ty] == -2) continue;

            for(int i=0; i<4; i++)
            {
                x = tx+dirx[i];
                y = ty+diry[i];
                if(grid[x][y]==0)
                {
                    return ret;
                }
                else if(grid[x][y]==1)
                {
                    //cout<<"xy: "<<x<<" "<<y<<endl;
                    grid[x][y] = -3;
                    q.push(x);
                    q.push(y);
                }
            }
        }
        jena = q;
        while(!fire.empty())
        {
            tx = fire.front();
            fire.pop();
            ty = fire.front();
            fire.pop();
            for(int i=0; i<4; i++)
            {
                x = tx+dirx[i];
                y = ty+diry[i];

                if(grid[x][y]!=-2 && grid[x][y]!=0 && grid[x][y]!=-1)
                {
                    grid[x][y] = -2;
                    p.push(x);
                    p.push(y);
                }
            }
        }
        fire = p;
    }
    return -1;
}
int main()
{
    int tc,r,c;
    scanf("%d",&tc);
    for(int t=1; t<=tc ; t++)
    {
        memset(grid, 0, sizeof grid);
        scanf("%d%d",&r,&c);
        for(int i=1; i<=r; i++)
        {
            scanf("%s",str);
            for(int j = 1; j<=c ; j++)
            {
                if(str[j-1]=='#')
                {
                    grid[i][j] = -1;
                }
                else if(str[j-1]=='.')
                {
                    grid[i][j] = 1;
                }
                else if(str[j-1] == 'J')
                {
                    grid[i][j] = -3;
                    jena.push(i);
                    jena.push(j);
                }
                else if(str[j-1] == 'F')
                {
                    grid[i][j] = -2;
                    fire.push(i);
                    fire.push(j);
                }
            }
        }
        int ans = bfs();
        printf("Case %d: ",t);
        if(ans>=0) printf("%d\n",ans);
        else printf("IMPOSSIBLE\n");
        while(!jena.empty()) jena.pop();
        while(!fire.empty()) fire.pop();
    }
    return 0;
}

