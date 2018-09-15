#include<bits/stdc++.h>
using namespace std;
#define mx 10000007
#define ll long long
vector<int> prime;
bitset<mx>bs;
int main()
{
    for(ll i=2; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i)
                bs.set(j);
        }
    }
    int tc,cs=1;
    ll num;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld",&num);
        while(num%2==0) num/=2;
        int id = 1;
        ll pf = prime[id];
        ll ans = 1;
        while(pf*pf <= num){
            if(num%pf==0){
                ll po = 0;
                while(num%pf==0){
                    num/=pf;
                    po++;
                }
                ans*=(po+1);
            }
            id++;
            if(id==prime.size())break;
            pf = prime[id];
        }
        if(num>1) ans*=2LL;
        ans--;
        printf("Case %d: %lld\n",cs++,ans);
    }
}
