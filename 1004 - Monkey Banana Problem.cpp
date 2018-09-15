#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll grid[205][102];
ll dp[205][102];
ll process(int i, int j, int n)
{
    if(i<0 ||i>=2*n-1 ||j<0 || j>=2*n-1) return 0;
    if(grid[i][j]==-1) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ret1 =0,  ret2=0;
    if(i<n-1){
        ret1 = grid[i][j]+process(i+1,j,n);
        ret2 = grid[i][j]+process(i+1, j+1,n);
    }
    else{
        ret1 = grid[i][j]+process(i+1,j,n);
        ret2 = grid[i][j]+process(i+1,j-1,n);
    }
    dp[i][j] = max(ret2, ret1);
    //cout<<"pro: "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    return dp[i][j];
}
int main()
{
    //freopen("out.txt","w", stdout);
    int tc,n;scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        memset(grid, -1, sizeof grid);
        memset(dp, -1, sizeof dp);
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++)
                scanf("%lld",&grid[i-1][j]);
        }
        int k=n+1;
        for(int i=n-1; i>=1; i--,k++){
            for(int j=0; j<i; j++)
                scanf("%lld",&grid[k-1][j]);
        }
        printf("Case %d: %lld\n",t,process(0,0,n));
    }
    return 0;
}