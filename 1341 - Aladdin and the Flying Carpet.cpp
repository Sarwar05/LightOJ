#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
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
int nod(ll num)
{
    int ret = 1;
    int id = 0, pf = prime[0];
    while(1LL*pf*pf <= num){
        int po = 0;
        while(num%pf==0) po++, num/=pf;
        ret*=(po+1);
        pf = prime[++id];
    }
    if(num!=1) ret*=2;
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
        int ans;
        if(sqrt(area)>side1){
            ans = nod(area);
            for(int i=1; i<side1; i++)
                if(area%i==0) ans-=2;
        }
        else ans = 0;
        printf("Case %d: %d\n", cs++, ans/2);
    }
}
