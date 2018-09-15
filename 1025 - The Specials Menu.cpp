#include<bits/stdc++.h>
using namespace std;
#define ll long long
char str[62];
ll dp[62][62];
int len;
ll allLCS(int i, int j)
{
    if(i>=len||j<0) return 0;
    if(i==j) return 1;
    if(i+1==j){
        if(str[i]==str[j]) return 3;
        else return 2;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ret = 0;
    if(str[i]==str[j]){
        ret = allLCS(i, j-1);
        ret += allLCS(i+1, j);
        ret++;
    }
    else{
        ret = allLCS(i, j-1);
        ret += allLCS(i+1, j);
        ret -= allLCS(i+1, j-1);
    }
    return dp[i][j] = ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",str);
        len = strlen(str);
        memset(dp,-1,sizeof dp);
        printf("Case %d: %lld\n",cs++, allLCS(0,len-1));
    }
    return 0;
}
/** 15 8 11
3
SALADS
PASTA
YUMMY
*/

