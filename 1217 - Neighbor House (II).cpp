#include<bits/stdc++.h>
using namespace std;
#define mx 1002
int n;
int arr[mx];
int dp[mx][2];
int vis[mx][2], color;
int solve(int pos, bool takenOne)
{
    if(pos>n) return 0;
    if(pos==n)
    {
        if(!takenOne) return arr[n];
        else return 0;
    }
    if(vis[pos][takenOne] == color) return dp[pos][takenOne];
    vis[pos][takenOne] = color;
    return dp[pos][takenOne] = max(solve(pos+1, takenOne),arr[pos] + solve(pos+2, takenOne||(pos==1)) );
}
int main()
{
    int tc,cs=1;
    color = 0;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
        }
        color++;
        printf("Case %d: %d\n", cs++, solve(1,0));
    }
    return 0;
}
