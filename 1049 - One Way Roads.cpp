
#include<bits/stdc++.h>
using namespace std;
#define mx 111
int mat[mx][mx];
int main()
{
    int tc,n,a,b,c;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        memset(mat, -1, sizeof mat);
        scanf("%d",&n);
        int x=-1,y=-1;
        for(int i=1; i<=n; i++){
            scanf("%d%d%d",&a,&b,&c);
            mat[a][b] = 0;
            mat[b][a] = c;
            if(a==1 || b==1){
                if(x == -1)
                    x = max(a,b);
                else y = max(a,b);
            }
        }
        int vis[111];int ans1, ans2;

        memset(vis, 0, sizeof vis);
        vis[1] = vis[x] = 1; ans1=mat[1][x];
        for(int i=1; i<=n-2; i++){
            for(int j=1; j<=n; j++){
                if(mat[x][j]>=0 && vis[j]==0 ){
                    vis[j] = 1;
                    ans1+=mat[x][j];
                    x = j;
                    break;
                }
            }
        }
        ans1+=mat[x][1];

        x = y;
        memset(vis, 0, sizeof vis);
        vis[1] = vis[x] =  1;ans2=mat[1][x];
        for(int i=1; i<=n-2; i++){
            for(int j=1; j<=n; j++){
                if(mat[x][j]>=0 && vis[j]==0 ){
                    vis[j] = 1;
                    ans2+=mat[x][j];
                    x = j;
                    break;
                }
            }
        }
        ans2+=mat[x][1];

        printf("Case %d: %d\n",t, min(ans1, ans2));
    }

    return 0;
}

