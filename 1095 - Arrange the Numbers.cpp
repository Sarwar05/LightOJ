#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define mod 1000000007
#define ll long long
int ncr[mx][mx], fact[mx];
int nCr(int n, int r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(ncr[n][r]!=-1) return ncr[n][r];
    return ncr[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}
/// from n item derangement first k items
int derange(int n,int k)
{
    ll ret = fact[n];
    for(int i=1; i<=k; i++){
        ret+=((i%2==1? -1LL : 1LL) * fact[n-i] * nCr(k,i))%mod;
        ret+=mod;
        ret%=mod;
    }
    return ret;
}
int main()
{
    memset(ncr, -1, sizeof ncr);
    fact[0] = 1;
    for(ll i=1; i<=1000; i++) fact[i] = (fact[i-1]*i)%mod;
    int tc,cs=1,n,m,k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&m,&k);
        ll way = nCr(m,k);
        way = (way*derange(n-k,m-k))%mod;
        printf("Case %d: %d\n",cs++, (int)way);
    }
}
