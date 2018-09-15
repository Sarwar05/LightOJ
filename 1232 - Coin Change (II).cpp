#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int dp[10005];
int coin[105];
int k, n;
int main()
{
    int  tc, cs=1;
    scanf("%d",&tc);
    while(tc--){
        memset(dp, 0, sizeof dp);
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; i++){
            scanf("%d", &coin[i]);
        }
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                if(coin[i]<=j)
                    dp[j] = (dp[j] + dp[j-coin[i]])%mod;
            }
        }
        printf("Case %d: %d\n", cs++, dp[k]);
    }
    return 0;
}
