
#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
#define m 1000003
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
int main()
{
    //freopen("out.txt","w",stdout);
    calc_inv_fact();
    calc_fact();
    int a,b,tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
            scanf("%d%d",&a, &b);
        printf("Case %d: %lld\n",t, (((fact[a]*inv_fact[b])%m)*inv_fact[a-b])%m);
    }
    ///http://math.stackexchange.com/questions/1024662/calculating-ncr-mod-m-using-inverse-multiplicative-factors

    return 0;
}
