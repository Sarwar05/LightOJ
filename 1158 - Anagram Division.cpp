#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[(1<<10) + 2][1003];
char s[12]; int d, sz;
ll fun(int mask, int mod)
{
    if(mask == (1<<sz)-1) return mod==0;
    ll& ret = dp[mask][mod];
    if(ret!=-1) return ret;
    ret = 0;
    mod*=10;
    int used[11] = {0};
    for(int i=0; i<sz; i++){
        if(mask&(1<<i));
        else{
            if(used[s[i]-'0'] > 0) continue;
            used[ s[i]-'0' ]++;
            ret+=fun( mask|(1<<i) , (mod+(s[i]-'0'))%d);
        }
    }
    return ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%s %d",s,&d);
        sz = strlen(s);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n", cs++, fun(0,0));
    }
}
