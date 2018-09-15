#include<bits/stdc++.h>
using namespace std;
#define mx 101
int mat[mx][mx];
void floyd(int n)
{
    for(int k=1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++)
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j] );
        }
    }
}
int main()
{
    int tc,n,m,a,b,c;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++){
            for(int j = 1; j<=n; j++)
                mat[i][j] = 1000000;
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&a,&b,&c);
            if(c<mat[a][b])
                mat[a][b] = mat[b][a] = c;
        }
        floyd(n);
        if(mat[1][n]==1000000)
            printf("Case %d: Impossible\n",t);
        else
            printf("Case %d: %d\n",t,mat[1][n]);
    }

    return 0;
}

