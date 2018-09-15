
#include<bits/stdc++.h>
using namespace std;
#define mx 51
#define mod 100000007
int coin[mx];
int use[mx];
int dp[mx][1002];

int coinChange(int ind,int need)
{
    if(ind<0){
        if(need==0) return 1;
        return 0;
    }
    if(dp[ind][need] != -1) return dp[ind][need];
    int ret = 0;
    for(int i=0; i<=use[ind]; i++){
        if(need-(coin[ind]*i)>=0)
            ret = (ret+ coinChange(ind-1,  need-(coin[ind]*i)))%mod;
    }
    return  dp[ind][need] = ret;
}
int main()
{
    int tc,a;int n,k;
    scanf("%d",&tc);
    for(int cs= 1; cs<=tc; cs++){
        memset(dp, -1, sizeof dp);
        scanf("%d%d",&n,&k);;
        for(int i=0; i<n; i++) scanf("%d",&coin[i]);
        for(int i=0; i<n; i++) scanf("%d",&use[i]);
        printf("Case %d: %d\n", cs, coinChange(n-1,k));
    }
    return 0;
}
