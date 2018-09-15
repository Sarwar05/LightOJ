#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}
int main()
{
    int tc, cs=1;
    ll a,b,c,d,e,x,y, mn;
    scanf("%d", &tc);
    while(tc--){
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        x = abs(a-c);
        y = abs(b-d);
        printf("Case %d: %lld\n",cs++,gcd(x,y)+1);
    }
    return 0;
}
 