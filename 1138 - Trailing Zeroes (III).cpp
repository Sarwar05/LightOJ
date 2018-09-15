#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll zeroes(ll a)
{
    ll p = 5;
    ll ret = 0;
    while(a/p !=0){
        ret = ret + a/p;
        p = p*5;
    }
    return ret;
}
int main()
{
    int tc,cs=1; ll n, lo, hi, mid,ans,x;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld",&n);
        lo = 1, hi = 10000000000;
        ans = 10000000000;
        while(lo<=hi){
            mid = (lo+hi)/2;
            x = zeroes(mid);
            if(x==n){
                if(mid<ans) ans= mid;
                hi = mid-1;
            }
            else if(x>n){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        printf("Case %d: ",cs++);
        if(ans==10000000000) printf("impossible\n");
        else printf("%lld\n", ans);
    }
    return 0;
}

