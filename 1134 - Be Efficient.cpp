#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[100002];
int main()
{
    int tc,n,m,a,cs=1;
    scanf("%d",&tc);
    while(tc--){
        memset(cnt, 0, sizeof cnt);
        scanf("%d%d",&n,&m);
        ll ans = 0;
        int sum = 0;
        cnt[0] = 1;
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            sum = (sum+a)%m;
            cnt[sum]++;
        }
        for(int i=0; i<m; i++){
            ll x = cnt[i];
            ans+=((x*(x-1))/2);
        }
        printf("Case %d: %lld\n", cs++,ans);
    }
}
