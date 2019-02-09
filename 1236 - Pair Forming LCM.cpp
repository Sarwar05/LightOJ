/// https://math.stackexchange.com/questions/4152/pairs-of-numbers-with-a-given-lcm
/**
 Let n = p1^a1 * p2^a2.... pk^ak
Let two numbers x and y such that lcm(a, b) = n. Let their prime factorization be x = p1^b1 * p2^b2 ... pk^bk and
y = p1^c1, p2^c2 .. pk^ck. Then at least one of (b_i, c_i) is equal to a_i and each of these can be at most a_i.
So let one of them be equal to a_i, the other one can have a_i+1 values (including zero) and since you can select two of them to be equal to a_i there are 2*(a_i + 1) - 1 = 2*a_i + 1 ways in total for each p_i. (minus one for the case where both are equal to a_i)

So, in total there are (2*a1+1)(2*a2+1)...(2*ak+1) ordered pairs of integers x and y.
*/
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
