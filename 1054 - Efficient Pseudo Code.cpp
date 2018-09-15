#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll bigMod(ll a, ll p)
{
    if(p==0) return 1;
    ll x = bigMod(a,p/2);
    x = (x*x);
    if(x>=mod) x%=mod;
    if(p%2==1)
        x = (x*a);
    if(x>=mod) x%=mod;
    return x;
}
int arr[65537] ={0};
vector<ll> prime;
void sieve()
{
    for(ll i=2; i<65537; i++){
        if(arr[i]==0){
            prime.push_back(i);
            for(ll j = i*i; j<65537; j+=i)
                arr[j] = 1;
        }
    }
}
int main()
{
    sieve();
    int n,m, num; ll power, ans;
    int tc; scanf("%d",&tc);
    for(int cs=  1; cs<=tc; cs++){
        scanf("%d%d", &n,&m);
        ans = 1;
        int i=0;num = n;
        while(prime[i]*prime[i]<=num){
            power = 0;
            if(num%prime[i]==0){
                while(num%prime[i]==0){
                    num/=prime[i];
                    power++;
                }
            }
            power*=m;
            ans = ((ans*(bigMod(prime[i], power+1)-1+mod)%mod )* bigMod(prime[i]-1, mod-2) )%mod;
            i++;
        }
        if(num>1){
            power = 1;
            power*=m;
            ans = ((ans*(bigMod(num, power+1)-1+mod)%mod )* bigMod(num-1, mod-2) )%mod;
        }
        printf("Case %d: %lld\n", cs, ans);
    }

    return 0;
}
