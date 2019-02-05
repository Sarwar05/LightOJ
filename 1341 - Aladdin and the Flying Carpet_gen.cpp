/// as NOD of 1e12 can be ~170, so we can generate
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, int>
#define mx 1000006
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
vector<pii> factor;
void nod(ll num)
{
    int id = 0, pf = prime[0];
    while(1LL*pf*pf <= num){
        int po = 0;
        while(num%pf==0) po++, num/=pf;
        if(po) factor.push_back(make_pair(pf,po));
        pf = prime[++id];
    }
    if(num!=1) factor.push_back(make_pair(num, 1));
}
int sq;
ll lo, hi;

int solve(int pos, ll div)
{
    if(div>hi) return 0;
    if(pos==factor.size())
        return (div>=lo && div<=hi && div!=sq);
    int ret = 0;
    for(int i=0; i<=factor[pos].second; i++){
        ret+=solve(pos+1, div);
        div*=factor[pos].first;
    }
    return ret;
}
int main()
{
    sieve();
    int tc,cs=1;
    ll area, side1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&area, &side1);
        factor.clear();
        nod(area);
        lo = side1;
        hi = area/side1;
        sq = sqrt(area);
        if(1LL*sq*sq != area) sq = -1;
        int ans = solve(0,1);
        printf("Case %d: %d\n", cs++, ans/2);
    }
}
