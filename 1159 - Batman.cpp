#include<bits/stdc++.h>
using namespace std;
int dp[51][51][51];
char str1[51],str2[51],str3[51];
int len1,len2,len3;
int lcs(int i, int j, int k)
{
    if(i>=len1 || j>=len2 || k>=len3) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int r[8] = {0};
    if(str1[i]==str2[j] && str1[i]==str3[k]){
        r[0] = 1 + lcs(i+1, j+1, k+1);
    }
    else{
        r[1] = lcs(i, j, k + 1);
        r[2] = lcs(i, j+ 1, k );
        r[3] = lcs(i, j+ 1, k+ 1 );
        r[4] = lcs(i+ 1, j, k );
        r[5] = lcs(i+ 1, j, k+ 1 );
        r[6] = lcs(i+ 1, j+ 1, k );
        r[7] = lcs(i+ 1, j+ 1, k+ 1 );
 
    }
    int ret = 0;
    for(int ind=0; ind<8; ind++) ret = max(ret, r[ind]);
    return dp[i][j][k] = ret;
}
int main()
{
    int tc, cs=1;
    scanf("%d", &tc);
    while(tc--){
        scanf("%s%s%s",str1,str2,str3);
        len1 = strlen(str1);
        len2 = strlen(str2);
        len3 = strlen(str3);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n",cs++, lcs(0, 0,0));
    }
    return 0;
}
 
