/// https://math.stackexchange.com/questions/4152/pairs-of-numbers-with-a-given-lcm
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000107
vector<int> prime;
bitset<mx> bs;
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
void solve()
{
    ll num;
    scanf("%lld", &num);
    ll ans = 1;
    ll pf = prime[0];
    int id = 1;
    while(pf*pf <= num){
        int po = 0;
        while(num%pf==0) po++, num/=pf;
        ans*=( (2*po) + 1 );
        pf = prime[id++];
    }
    if(num!=1) ans*=(2*1 + 1);
    ans++;
    printf("%lld\n", ans/2);
}
int main()
{
    sieve();
    int tc, cs=1;
    scanf("%d", &tc);
    while(tc--){
        printf("Case %d: ", cs++);
        solve();
    }
}
