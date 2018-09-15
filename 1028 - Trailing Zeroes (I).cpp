#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int arr[1000005] = {0};
vector<ll> primes;
void sieve()
{
    for(ll i=2; i<1000005; i++){
        if(arr[i]==0){
            arr[i] = 1;
            primes.push_back(i);
            for(ll j = i*i; j<1000005; j+=i)
                arr[j] = 1;
        }
    }
}
int main()
{
    sieve();
    int tc,i;
    ll num,ans;
    scanf("%d",&tc);
    for(int t=1; t<=tc;  t++){
        scanf("%lld",&num);
        ans = 1;
        for(int i=0; primes[i]*primes[i]<=num; i++){
            ll power = 0;
            while(num%primes[i]==0){
                num/=primes[i];
                power++;
            }
            ans *= (power+1);
        }
        if(num!=1) ans*=2;
        printf("Case %d: %lld\n",t,ans-1);
    }

    return 0;
}
