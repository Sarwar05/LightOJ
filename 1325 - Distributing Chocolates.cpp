#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
/**
res = k^x
    let n = sqrt(mod)
    we can write x = n*i - j; 1<=i<=n, 0<=j<n
res = k^(n*i - j)
res = k^(n*i) * k^(-j)
res*k^(j) = k^(n*i)
like meet in the middle trick, calculate all possible RHS
ans then LHS, and then find collision.
*/
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
    int tc, cs=1,k, res;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&k, &res);
        int n = sqrt(mod);
        unordered_map<int, int> mp;
        for(int i=1; i<=n; i++)
            mp[ bigMod(k,i*n) ] = i;
        int ans = mod;
        for(int j=0; j<n; j++){
            int val = (1LL*bigMod(k,j)*res)%mod;
            if(mp.find(val)!=mp.end()){
                long long tem = 1LL*mp[val]*n - j;
                ans = min(1LL*ans, tem);
            }
        }
        printf("Case %d: %d\n", cs++, ans);
    }
}
