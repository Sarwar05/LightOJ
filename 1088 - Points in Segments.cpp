#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
int main()
{
    ll tc, cs=1,n,q,a,b,x,y;
    scanf("%lld",&tc);
    while(tc--){
        scanf("%lld%lld",&n,&q);
        vi arr(n);
        for(int i=0; i<n; i++) scanf("%lld",&arr[i]);
        printf("Case %lld:\n",cs++);
        while(q--){
            scanf("%lld%lld",&a,&b);
            x = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            y = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
            printf("%lld\n", y-x);
        }
    }
    return 0;
}
