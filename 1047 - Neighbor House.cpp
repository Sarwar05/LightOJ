#include<bits/stdc++.h>
using namespace std;;
int dp[22][5];
int cost[22][5];
int fun(int i, int j)
{
    if(i == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int res;
    if(j==1){
        res = cost[i][j] + min(fun(i-1, 2),fun(i-1, 3) );
    }
    else if(j==2){
        res = cost[i][j] + min( fun(i-1, 1) , fun(i-1, 3) );
    }
    else{
        res = cost[i][j] + min(fun(i-1, 2),fun(i-1, 1) );
    }
    //cout<<"for i j: "<<i<<" "<<j<<" get: "<<res<<endl;
    return dp[i][j] = res;
}
int main()
{
    int tc,n, cs=1;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d%d%d", &cost[i][1], &cost[i][2], &cost[i][3]);
        int ans = 10000000;
        memset(dp, -1, sizeof dp);
        ans = min(ans, fun(n,1));
        ans = min(ans, fun(n,2));
        ans = min(ans, fun(n,3));
        printf("Case %d: %d\n",cs++, ans);
    }
    return 0;
}
