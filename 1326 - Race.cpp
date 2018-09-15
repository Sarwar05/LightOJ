#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define mod 10056
int ncr[mx][mx] = {0};
int dp[mx];
//int nCr(int n, int r)
//{
//    int ret = 1;
//    for(int x=(n-r)+1; x<=n; x++)ret*=x;
//    for(int i=2; i<=r; i++) ret/=i;
//    return ret;
//}
//int fun(int n)
//{
//    if(dp[n]!=-1) return dp[n];
//    int ret = 0;
//    for(int i=1; i<=n; i++){
//        ret+=( fun(n-i)*(nCr(n,i)) );
//    }
//    return dp[n] = ret;
//}
void nCr_DP()
{
    for(int i=0; i<=1000; i++) ncr[i][0] = 1;
    ncr[0][0] = 1;
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=i; j++){
            if(i==j) ncr[i][j] = 1;
            else ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
        }
    }
}
int fun(int n)
{
    if(dp[n]!=-1) return dp[n];
    int ret = 0;
    for(int i=1; i<=n; i++){
        ret = (ret + (dp[n-i]*ncr[n][i])%mod)%mod;
    }
    return dp[n] = ret;
}
/// 3 == 420 == 838
void process()
{
    nCr_DP();
    //cout<<ncr[3][1]<<endl;cout<<ncr[3][2]<<endl;
    memset(dp, -1, sizeof dp);
    dp[0] = 1;
    for(int i=1; i<=1000; i++){
        dp[i] = fun(i);
        //cout<<i<<" "<<dp[i]<<endl;
    }
}
int main()
{
    process();
    int tc, cs=1,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        printf("Case %d: %d\n", cs++, dp[n]);
    }
    return 0;
}
