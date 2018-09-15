#include<bits/stdc++.h>
using namespace std;
int dp[1002][2],n;
int eat1[1002], eat2[1002];
int jump1[1002], jump2[1002];
int fun(int pos, int now)
{
    if(pos>n) return 0;
    int &ret = dp[pos][now];
    if(ret!=-1) return ret;
    ret = ( now ? eat2[pos] : eat1[pos] ) + min( fun(pos+1, now), (now ? jump2[pos] : jump1[pos]) + fun(pos+1, now ? 0 : 1) );
    return ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&eat1[i]);
        for(int i=1; i<=n; i++) scanf("%d",&eat2[i]);
        for(int i=1; i<n; i++) scanf("%d",&jump1[i]);
        for(int i=1; i<n; i++) scanf("%d",&jump2[i]);
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",cs++, min( fun(0,0), fun(0,1)));
    }
    return 0;
}
