#include<bits/stdc++.h>
using namespace std;
int own[51];
int opp[51];
int dp[51][51];
int func(int i,int j,int n)
{
    if(i==n || j==n) return 0;
    if(own[i]==-1 || opp[j] == -1) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(own[i]>opp[j]){
        own[i]=opp[j] = -1;
        dp[i][j] = 2 + func(i+1, j+1,n);
    }
    else if(own[i]==opp[j])
        dp[i][j] = 1 + func(i+1, j+1,n);
    else{
        int a = func(i+1, j,n);
        int b = func(i, j+1, n);
        dp[i][j] = max(a,b);
    }
    return dp[i][j];
}
int main()
{
    int tc,n,t,i,j,points,c,ind;
    scanf("%d",&tc);
    for( t=1; t<=tc; t++){
        scanf("%d",&n);
        for(i=0; i<n; i++) scanf("%d",&own[i]);
        for(i=0; i<n; i++) scanf("%d",&opp[i]);
        memset(dp, -1,sizeof dp);
        func(0,0,n);
        printf("Case %d: %d\n",t,points);
    }
    return 0;
}

