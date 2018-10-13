#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2000002
#define mod 1000000007
int fact[mx];
int bigMod(int b, int p)
{
    if(p==0) return 1;
    ll x = bigMod(b,p/2);
    x = (x*x)%mod;
    if(p%2==1) x = (x*b)%mod;
    return (int)x;
}
int solve(int n, int k)
{
    ll x = fact[n+k-1];
    x = (x*bigMod(fact[k-1],mod-2))%mod;
    x = (x*bigMod(fact[n],mod-2))%mod;
    return (int)x;
}
int main()
{
    fact[0] = 1;
    for(ll i=1; i<=2000000; i++)
        fact[i] = (fact[i-1]*i)%mod;
    int tc,cs=1,n,k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        printf("Case %d: %d\n",cs++, solve(n,k));
    }
}
