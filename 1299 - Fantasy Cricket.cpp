/// https://eltonrawn.quora.com/LightOJ-1299-dynamic-programming
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
char str[1002];
int sz;
int dp[1002][1002];
int fun(int pos, int free)
{
    if(pos==sz) return free==0;
    int& ret = dp[pos][free];
    if(ret!=-1) return ret;
    ret = 0;
    if(str[pos]=='U'){
        ret = fun(pos+1, free+1);
        ret =  (ret + 1LL*free*fun(pos+1, free))%mod;
    }
    else if(str[pos]=='D'){
        ret = (1LL*free*fun(pos+1, free))%mod;
        if(free)ret = (ret + 1LL*free*free*fun(pos+1, free-1))%mod;
    }
    else ret = fun(pos+1, free);
    return ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
       scanf("%s",str) ;
       sz = strlen(str);
       memset(dp, -1, sizeof dp);
       printf("Case %d: %d\n",cs++, fun(0,0));
    }
}
