
#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define pii pair<ll, int>
#define mx 2750006
bitset<mx> bs;
vector<int> prime;
void sieve()
{
    for(ll i=2; i<mx; i++){
        if(!bs[i]){
            for(ll j = i*i; j<mx; j+=i)
                bs[j] = 1;
            prime.push_back(i);
        }
    }
}
ll bigpow(ll b, ll p)
{
    if(p==0) return 1;
    ll x = bigpow(b, p/2);
    x*=x;
    if(p%2) x*=b;
    return x;
}
ll get(ll pf, ll po)
{
    ll ret = bigpow(pf, po+1) - 1;
    return ret/(pf-1);
}
ll sod(ll num)
{
    ll ret = 1;
    int id = 0, pf = prime[0];
    while(1LL*pf*pf <= num){
        int po = 0;
        while(num%pf==0) po++, num/=pf;
        ret*=get(pf, po);
        pf = prime[++id];
    }
    if(num!=1) ret*=get(num,1);
    return ret;
}
void check()
{
    sieve();
    int cnt = 0;
    for(int i=1; i<=100; i++){
        cnt+=(sod(i)%2);
        cout<<i<<" ----- "<<sod(i)%2<<endl;//" >>> "<<i - cnt<<endl;
    }
}
ll arr[mx];
int id = 0;
void process()
{
    for(ll i=1; i<=1500000; i++){
        arr[id++] = i*i;
        i++;
        arr[id++] = i*i;
        arr[id++] = (i*i)/2;
    }
    sort(arr, arr+id);
}
int main()
{
    //check();
    ll n;
    process();
    int tc, cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld", &n);
        int ans = upper_bound(arr, arr+id, n) - arr;
        printf("Case %d: %lld\n",cs++, n-ans);
    }
}
