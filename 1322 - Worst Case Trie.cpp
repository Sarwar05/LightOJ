#include<bits/stdc++.h>
using namespace std;
#define mod 10000
int dp[mod+2];
int main()
{
    dp[0] = 1;
    for(int i=1; i<=mod; i++){
        dp[i] = (1 + (dp[i-1]*i)%mod)%mod;
    }
	int tc,n,cs=1;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		if(n<=5) printf("Case %d: %d\n",cs++,dp[n]);
        else printf("Case %d: %04d\n",cs++,dp[n%mod]);
	}
}
