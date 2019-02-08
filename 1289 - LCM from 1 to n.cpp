#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mx 100000008
bitset<mx> bs;
int prime[5761459];
unsigned int dp[5761459];
int id = 0;
void sieve()
{
    for(ll i=2; i<mx; i++){
        if(!bs[i]){
            for(ll j = i*i; j<mx; j+=i)
                bs[j] = 1;
            prime[id++] = i;
        }
    }
    dp[0] = 2;
    for(int i=1; i<id; i++)
        dp[i] = dp[i-1]*prime[i];
}
void solve()
{
    int n;
    scanf("%d", &n);
    int index = upper_bound(prime, prime+id, n) - prime - 1;
    unsigned int ans = dp[index];
    for(int i=0; i<=index && 1LL*prime[i]*prime[i]<=n; i++){
        int now = prime[i];
        while(1LL*now*prime[i]*prime[i] <=n)
            now*=prime[i];
        ans*=now;
    }
    printf("%u\n", ans);
}
int main()
{
    sieve();
    int tc, cs=1;
    scanf("%d",&tc);
    while(tc--){
        printf("Case %d: ", cs++);
        solve();
    }
}
