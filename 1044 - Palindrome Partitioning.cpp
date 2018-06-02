// https://sarwar05.blogspot.com/2018/06/1044-palindrome-partitioning.html
#include<bits/stdc++.h>
using namespace std;
#define inf 10000007
char str[1003];
int dp[1002];
vector<int> Next[1002];
int len;
int fun(int now)
{
    if(now==len) return 0;
    if(dp[now]!=-1) return dp[now];
    int ret = inf;
    for(int i=0; i<Next[now].size(); i++){
        ret = min(ret,1+fun(Next[now][i]));
    }
    return dp[now] = ret;
}
void process()
{
    for(int i=0; i<=len; i++) Next[i].clear();
    for(int center = 0; center<len; center++){/// for odd length palindrome
        int i,j;
        i=j=center;
        while(str[i]==str[j])
        {
            Next[i].push_back(j+1);
            i--;
            j++;
            if(i<0 || j==len) break;
        }
    }
    for(int center = 0; center<len; center++){/// for even length palindrome
        int i,j;
        i=j=center;
        j++;
        while(str[i]==str[j])
        {
            Next[i].push_back(j+1);
            i--;
            j++;
            if(i<0 || j==len) break;
        }
    }
}
int main()
{
    int tc, cs=1;
    scanf("%d", &tc);
    while(tc--){
        scanf("%s",str);
        len = strlen(str);
        process();
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n",cs++,fun(0));
    }
    return 0;
}


