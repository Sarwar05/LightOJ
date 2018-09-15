#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
char str[105];
int len;
int fun(int i, int j)
{
    if(i>=len || j<0)  return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int res;
    if(str[i]==str[j]){
        res = 1 + fun(i+1, j-1);
    }
    else{
        res = max( fun(i, j-1) ,fun(i+1, j) );
    }
    return dp[i][j] = res;
}
int main()
{
    int tc, cs=1, ans;
    scanf("%d", &tc);
    while(tc--){
        scanf("%s", str);
        len = strlen(str);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", cs++, len-fun(0, len-1));
    }
    return 0;
}
