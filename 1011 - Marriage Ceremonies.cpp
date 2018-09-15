#include<bits/stdc++.h>
using namespace std;
int grid[18][18];
int dp[17][(1<<16)+2];
int n;
bool check(int val, int pos)
{
    return !((1<<pos) & val);
}
int Set(int val, int pos)
{
    return (val|(1<<pos));
}
int fun(int row,int col)
{
    if(row>=n) return 0;
    if(dp[row][col] != -1) return dp[row][col];
    int ret = 0;
    for(int i=0; i<n; i++){
        if(check(col,i)){
            ret = max(ret,grid[row][i] + fun(row+1,Set(col,i)));
        }
    }
    return dp[row][col] = ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d",&grid[i][j]);
            }
        }
        memset(dp,-1,sizeof dp);
        int ans = fun(0,0);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
