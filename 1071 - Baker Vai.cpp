#include<bits/stdc++.h>
using namespace std;
int grid[102][102], dp[102][102][102][3];
int m,n;
int fun(int i, int j, int k, int move)
{
    if(i==m && j==n-1 && k==n) return grid[m][n-1] + grid[m][n];
    int& ret = dp[i][j][k][move];
    if(ret!=-1) return ret;
    ret = 0;
    if(move==0){/// left pawn goes right
        if(j+1 < k) ret = max(ret, fun(i,j+1,k,move) + grid[i][j]);
        ret = max(ret, fun(i,j,k,move+1));
    }
    else if(move==1){/// right pawn goes right
        if(k+1 <= n) ret = max(ret, fun(i,j,k+1,move) + grid[i][k]);
        ret = max(ret, fun(i,j,k,move+1));
    }
    else{/// both pawn moves down
        if(i<m) ret = max(ret, fun(i+1,j,k,0) + grid[i][j] + grid[i][k]);
    }
    return ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&m,&n);
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&grid[i][j]);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", cs++, fun(1,1,2,0));
    }
}
/**
2
3 3
1 1 1
1 0 1
1 1 1
3 4
1 1 0 1
1 1 1 1
0 1 10 1
*/
