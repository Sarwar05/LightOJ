#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
#define ll long long
int flag[mx];
bitset<mx> bs;
void sieve()
{
    for(int i=1; i<mx; i++) flag[i] = 1;
    for(ll i=2; i<mx; i++){
        if(!bs[i]){
            for(ll j = i; j<mx; j+=i){
                bs[j] = 1;
                flag[j]*=-1;
            }
            ll sq = i*i;
            for(ll j = sq; j<mx; j+=sq)
                flag[j] = 0;
        }
    }
}
int main()
{
    sieve();
    ll tc,n,m,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&n,&m);
        ll ans = 0;
        for(ll i = min(n,m); i>=1; i--)
            ans+=(flag[i]*(n/i)*(m/i));
        if(n>0)ans++;
        if(m>0)ans++;
        printf("Case %lld: %lld\n", cs++,ans);
    }
}
