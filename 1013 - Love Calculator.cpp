#include<bits/stdc++.h>
using namespace std;
#define N 32
#define ll long long
int lcs[N][N];
ll dp[N][N][N*2];
char str1[N], str2[N];
int l1,l2,len;
int findLCS(int i,int j)
{
    if(i<0 || j<0) return 0;
    if(lcs[i][j]!=-1) return lcs[i][j];
    int ret = 0;
    if(str1[i]==str2[j]){
        ret = findLCS(i-1, j-1) + 1;
    }
    else{
        ret = max(findLCS(i-1, j), findLCS(i, j-1));
    }
    return lcs[i][j] = ret;
}
ll call(int i, int j, int l)
{
    if(i>l1 || j>l2) return 0;
    if(l==len){
        if(i==l1 && j==l2) return 1;
        else return 0;
    }
    if(dp[i][j][l]!=-1) return dp[i][j][l];
    ll ret = 0;
    if(str1[i]==str2[j]){
        ret = call(i+1, j+1, l+1);
    }
    else{
        ret = (call(i+1, j, l+1)) + (call(i, j+1, l+1));
    }
    return dp[i][j][l] = ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        memset(lcs,-1,sizeof lcs);
        memset(dp, -1, sizeof dp);
        scanf("%s%s",str1,str2);
        l1 = strlen(str1);
        l2 = strlen(str2);
        len = l1+l2-findLCS(l1-1, l2-1);
        ll ans = call(0,0, 0);
        printf("Case %d: %d %lld\n",cs++,len,ans);
    }
    return 0;
}
