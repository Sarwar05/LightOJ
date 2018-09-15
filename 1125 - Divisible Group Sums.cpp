#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll input[202];
int arr[202],d;
ll dp[202][12][22];
ll fun(int pos, int rem, int mod)
{
    if(pos==0||rem==0){
        return (rem==0 && mod==0);
    }
    ll& ret = dp[pos][rem][mod];
    if(ret!=-1) return ret;
    ret = 0;
    ret+=fun(pos-1, rem, mod);
    ret+=fun(pos-1, rem-1, (mod+arr[pos])%d);
    return ret;
}
int main()
{
    int tc,cs=1,q,n,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++){
            scanf("%lld",&input[i]);
        }
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&d,&m);
            for(int i=1; i<=n; i++){
                arr[i] = input[i]%d;
                arr[i] = (arr[i] + d)%d;
            }
            memset(dp, -1, sizeof dp);
            printf("%lld\n",fun(n,m,0));
        }
    }
    return 0;
}
