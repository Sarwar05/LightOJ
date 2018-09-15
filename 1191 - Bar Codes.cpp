#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[52][52][52];
ll fun(int rem, int bar, int lim)
{
    if(rem<=0){
        if(bar==0) return 1;
        else return 0;
    }
    if(bar==0) return 0;
    ll& ret = dp[rem][bar][lim];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=1; i<=lim; i++){
        if(rem-i >=0)
            ret+=fun(rem-i, bar-1, lim);
    }
    return ret;
}
int main()
{
    memset(dp, -1, sizeof dp);
    int tc,cs=1,n,k,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&k,&m);
        printf("Case %d: %lld\n",cs++, fun(n,k,m));
    }
    return 0;
}
