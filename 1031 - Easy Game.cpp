#include<bits/stdc++.h>
using namespace std;
int n,arr[102];
int dp[102][102];
int solve(int i, int j)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ret = -10000000,sum=0;
    for(int id=i; id<=j; id++){
        sum+=arr[id];
        ret = max(ret, sum-solve(id+1,j));
    }
    sum=0;
    for(int id=j; id>=i; id--){
        sum+=arr[id];
        ret = max(ret, sum-solve(i,id-1));
    }
    return dp[i][j] = ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
        }
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",cs++,solve(1,n));
    }
    return 0;
}
