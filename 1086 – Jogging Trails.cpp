#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000000LL
ll mat[17][17];
int n,m, deg[17];
ll dp[(1<<16)+2];
ll fun(int mask)
{
    if(mask == (1<<(n+1))-1) return 0;
    ll& ret = dp[mask];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i=1; i<=n; i++){
        if(mask&(1<<i));
        else{
            int nxtMask = mask|(1<<i);
            for(int j = i+1; j<=n; j++){
                if(mask&(1<<j));
                else{
                    ret = min(ret, fun(nxtMask|(1<<j)) + mat[i][j]);
                }
            }
        }
    }
    return ret;
}
ll solve(int n)
{
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }
    memset(dp, -1, sizeof dp);
    int mask = 0;
    for(int i=0; i<=n; i++)
        if(deg[i]%2==0)
        mask = mask|(1<<i);
    return fun(mask);
}
int main()
{
    int tc,cs=1,a,b;
    ll c;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<=16; i++){
            deg[i] = 0;
            for(int j=0; j<=16; j++)
                mat[i][j] = inf;
        }
        ll ans = 0;
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d%lld",&a,&b,&c);
            deg[a]++;
            deg[b]++;
            ans+=c;
            mat[a][b] = min(mat[a][b], c);
            mat[b][a] = min(mat[b][a], c);
        }
        ans+=solve(n);
        printf("Case %d: %lld\n",cs++, ans);
    }
}
