#include<bits/stdc++.h>
using namespace std;
int dp[102][102];
char str1[102],str2[102];
int len1,len2;
int LCS(int i, int j)
{
    if(i>=len1 || j>=len2)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret = 0;
    if(str1[i]==str2[j])
        ret = 1 + LCS(i+1,j+1);
    else
        ret = max(LCS(i,j+1), LCS(i+1,j));
    return dp[i][j] = ret;
}
bool done;
void printLCS(int i, int j, string str, int need)
{
    if(done) return;
    if(need == 0)
    {
        printf("%s\n",str.c_str());
        done = true;
        return;
    }
    for(char ch='a'; ch<='z'; ch++)
    {
        for(int id1 = i; id1<len1; id1++)
        {
            if(ch==str1[id1])
            {
                for(int id2 = j; id2<len2; id2++)
                {
                    if(ch==str2[id2])
                    {
                        if(dp[id1][id2]==need){
                            printLCS(id1+1, id2+1, str+ch, need-1);
                        }
                        if(done) return;
                    }
                    if(done) return;
                }
                if(done) return;
            }
            if(done) return;
        }
        if(done) return;
    }
    if(done) return;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s%s",str1,str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        memset(dp,-1,sizeof dp);
        int lcs = LCS(0,0);
        printf("Case %d: ",cs++);
        if(lcs==0)
            printf(":(\n");
        else
        {
            done = false;
            printLCS(0,0,"",lcs);
        }
    }
    return 0;
}
