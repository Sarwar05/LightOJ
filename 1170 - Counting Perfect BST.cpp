#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define m 100000007
#define ll long long int
ll fact[mx];
ll inv_fact[mx];
void calc_fact()
{
    fact[0] = 1;
    for(int i=1; i<mx; i++){
        fact[i] = (fact[i-1]*(ll)i)%m;
    }
}
ll big_mod(ll a, ll p)
{
    if(p==0) return 1;
    ll x = big_mod(a,p/2);
    x = (x*x)%m;
    if(p%2==1)
        x = (x*a)%m;
    return x;
}
void calc_inv_fact()
{
    inv_fact[0] = 1;
    inv_fact[1] = 1;
    for(int i=2; i<mx; i++){
        inv_fact[i] = (inv_fact[i-1]*big_mod(i,m-2))%m;
    }

}
ll pow(ll a, ll b)
{
    if(b==0) return 1;
    ll x = pow(a,b/2);
    x = x*x;
    if(b%2==1)
        x = x*a;
    return x;
}
ll arr[mx] = {0};
int main()
{
    calc_inv_fact();
    calc_fact();
    int tc, cs=1;
    vector<ll> v;
    map<ll , int> mp;
    for(ll i = 2; i <= 100000; ++i ){
      ll num = i*i;
      while(num <= 10000000000){
        if(num<=10000000000){
                if(mp[num]==0){
                    v.push_back(num);
                    mp[num]++;
                }
        }
        num*=i;
      }
    }
    sort(v.begin(), v.end());
    ll a, b, i;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&a, &b);
        int x = lower_bound(v.begin(), v.end(),a)-v.begin();
        int y = lower_bound(v.begin(), v.end(),b)-v.begin();
        if(mp.find(b)==mp.end()) y--;
        i = 0;
        if(x>y){
            printf("Case %d: 0\n", cs++);
            continue;
        }
        if(x<=y && x>=0 && y>=0) i = y-x+1;
        ll ans = ((((((fact[2*i]*inv_fact[i])%m)*inv_fact[i])%m)*big_mod(i+1, m-2))%m);
        printf("Case %d: %lld\n", cs++,ans);
    }
    return 0;
}
