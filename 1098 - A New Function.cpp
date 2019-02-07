#include<bits/stdc++.h>
using namespace std;
#define ll long long
void view()
{
    for(int num=1; num<=25; num++){
        vector<int> div(30, 0);
        for(int i=2; i<num; i++)
            if(num%i==0) div[i] = 1;
        printf("%2d ->> ", num);
        for(int i=2; i<=25; i++){
            if(div[i]) printf(" %2d", i);
            else printf("   ");
        }
        printf("\n");
    }
    /**
    we get a nice triangle
    sum from top left to its diagonal + its down
    */
}
int main()
{
    //view();
    int tc, cs=1;
    ll n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld",&n);
        ll ans = 0;
        int cnt = 0;
        for(ll i=2; i*i <= n; i++){
            ll j = n/i;
            ll tem = ((j*(j+1))/2) - ((i*(i-1))/2);
            tem+=( i*(j-i) );
            ans+=tem;
            cnt++;
        }
        printf("Case %d: %lld\n", cs++, ans);
    }
}
