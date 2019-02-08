#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc, cs=1, n;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        ll ans = n;
        int prev = n;
        for(ll i=2; i <= prev; i++){
            int now = n/i;
            ans+=((i-1)* (prev-now) );
            if(now>=i)
                ans+=now;
            prev = now;
        }
        printf("Case %d: %lld\n", cs++, ans);
    }
}
