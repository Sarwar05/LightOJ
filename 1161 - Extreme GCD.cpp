#include<bits/stdc++.h>
using namespace std;
#define mx 10002
#define lim 10000
#define ll long long
ll dp[mx][5];
ll nCr(int n, int r)
{
    if(r>n) return 0;
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1, r-1);
}
ll occ[mx], res[mx];
int main()
{
    memset(dp, -1, sizeof dp);
    int tc,cs=1,n,a;
    scanf("%d",&tc);
    while(tc--){
        memset(occ,0,sizeof occ);
        memset(res, 0, sizeof res);
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            occ[a]++;
        }
        for(int i=lim; i>=2; i--){
            int cnt = 0; ll mns = 0;
            cnt+=occ[i];
            for(int j=i*2; j<=lim; j+=i){
                cnt+=occ[j];
                mns+=res[j];
            }
            res[i] = nCr(cnt,4) - mns;
        }
        ll ans = nCr(n,4);
        for(int i=2; i<=lim; i++)ans-=res[i];
        printf("Case %d: %lld\n",cs++,ans);
    }
}
/**
3
4
2 4 6 1
5
1 2 4 6 8
10
12 46 100 131 5 6 7 8 9 10
*/
