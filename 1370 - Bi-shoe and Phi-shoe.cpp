#include<bits/stdc++.h>
using namespace std;
#define M 1000006
int phi[M];
void calculatePhi()
{
    for (int i = 1; i < M; i++) phi[i] = i;
    for (int p = 2; p < M; p++){
        if (phi[p] == p){   // p is a prime
            for (int k = p; k < M; k += p)
                phi[k] -= phi[k] / p;
        }
    }
}
int dp[M];
int main()
{
    calculatePhi();
    phi[1] = 0;
    for(int i = M-1; i>=1; i--)
        dp[ phi[i] ] = i;
    dp[M-1] = M-1;
    for(int i = M-2; i>=1; i--)
        if(dp[i]==0) dp[i] = dp[i+1];
        else dp[i] = min(dp[i], dp[i+1]);
    int tc,cs=1,n,a;
    scanf("%d",&tc);
    while(tc--){
        long long ans = 0;
        scanf("%d",&n);
        while(n--){
            scanf("%d", &a);
            ans+=dp[a];
        }
        printf("Case %d: %lld Xukha\n", cs++, ans);
    }
}
