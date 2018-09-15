#include<bits/stdc++.h>
using namespace std;
int coin[102], limit[102];
int dp[100005], used[100005];
int main()
{
    int tc,cs=1,n,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d", &n,&m);
        for(int i=1; i<=n; i++) scanf("%d",&coin[i]);
        for(int i=1; i<=n; i++) scanf("%d",&limit[i]);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        int ans=0;
        for(int i=1; i<=n; i++){
            memset(used, 0, sizeof used);
            int now = coin[i];
            for(int j=1; j<=m; j++){
                if(dp[j]) continue;
                int prev = j-now;
                if(prev<0) continue;
                else if(prev==0){
                    if(dp[j]==0){
                        ans++;
                        dp[j] = 1;
                        used[j]++;
                    }
                }
                else{
                    if(used[prev]==limit[i]) continue;
                    if(dp[j]==0 && dp[prev]){
                        ans++;
                        dp[j] = 1;
                        used[j] = used[prev] + 1;
                    }
                }
            }
        }
        printf("Case %d: %d\n", cs++,ans);
    }
    return 0;
}
