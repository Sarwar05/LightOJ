#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll LCM(ll a, ll b)
{
    return (a/__gcd(a,b))*b;
}
int main()
{
    int tc,cs=1,m;
    scanf("%d",&tc);
    ll n;
    while(tc--){
        scanf("%lld%d",&n,&m);
        vector<ll> v(m), arr;
        for(int i=0; i<m; i++) scanf("%lld",&v[i]);
        sort(v.begin(), v.end());
        for(int i=0; i<m; i++){
            if(v[i]==-1) continue;
            for(int j = i+1; j<m; j++){
                if(v[j]%v[i]==0)
                    v[j] = -1;
            }
        }
        for(int i=0; i<m; i++){
            if(v[i]!=-1)
                arr.push_back(v[i]);
        }
        m = arr.size();
        ll divisible = 0;
        for(ll i = (1LL<<m)-1; i>=1; i--){
            ll lcm = -1;
            for(ll j=0; i>=(1LL<<j); j++){
                if(i&(1LL<<j)){
                    if(lcm==-1) lcm = arr[j];
                    else lcm = LCM(lcm,arr[j]);
                }
                if(lcm>n) break;
            }
            if(lcm==-1 || lcm>n) continue;
            divisible+=(__builtin_popcount(i)%2==0?-1LL : 1LL)*(n/lcm);
        }
        printf("Case %d: %lld\n", cs++,n-divisible);
    }
}
