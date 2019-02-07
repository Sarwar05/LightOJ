#include<bits/stdc++.h>
using namespace std;
#define ll long long
int tc, cs=1, n, k, mod, sum,a;
int bigMod(int b, int p)
{
    if(p==0) return 1;
    int x = bigMod(b, p/2);
    x = (1LL*x*x)%mod;
    if(p%2) x = (1LL*x*b)%mod;
    return x;
}
int main()
{
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d%d",&n,&k,&mod);
        sum = 0;
        for(int i=1; i<=n; i++){
            scanf("%d", &a);
            a%=mod;
            sum = (sum+a)%mod;
        }
        int ans = bigMod(n, k-1);
        ans = (1LL*ans*k)%mod;
        ans = (1LL*ans*sum)%mod;
        printf("Case %d: %d\n", cs++, ans);
    }
}
