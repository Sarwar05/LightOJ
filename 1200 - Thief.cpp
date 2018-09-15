#include<bits/stdc++.h>
using namespace std;
int price[102], weight[102];
int dp[102][10002];
int fun(int pos, int rem)
{
    if(pos==0 || rem<=0) return 0;
    if(dp[pos][rem]!=-1) return dp[pos][rem];
    int ret1=0,ret2=0;
    if(weight[pos]<=rem)
        ret1 =  price[pos] + fun(pos,   rem-weight[pos]);
    ret2 =               fun(pos-1, rem);
    return dp[pos][rem] = max(ret1, ret2);
}
int main()
{
    int tc,cs=1,c,cap,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&cap);
        int tot = 0;
        for(int i=1; i<=n; i++){
            scanf("%d%d%d",&price[i],&c ,&weight[i]);
            tot+=(c*weight[i]);
        }
        printf("Case %d: ",cs++);
        if(tot>cap){
            printf("Impossible\n");
        }
        else{
            memset(dp, -1, sizeof dp);
            printf("%d\n",fun(n,cap-tot));
        }
    }
}
