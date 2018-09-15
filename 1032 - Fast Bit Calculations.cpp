#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arr[32];
ll dp[32][2][32][2];
ll fun(int pos, int isSmall, ll tot, int prev)
{
    if(pos==32) return tot;
    ll &ret = dp[pos][isSmall][tot][prev];
    if(ret!=-1) return ret;
    ret=0;
    if(isSmall){
        if(prev){
            ret+=fun(pos+1, isSmall, tot+1, 1);
            ret+=fun(pos+1, isSmall, tot, 0);
        }
        else{
            ret+=fun(pos+1, isSmall, tot, 1);
            ret+=fun(pos+1, isSmall, tot, 0);
        }
    }
    else{
        if(arr[pos]){
            if(prev){
                ret+=fun(pos+1, isSmall, tot+1, 1);
                ret+=fun(pos+1, 1, tot, 0);
            }
            else{
                ret+=fun(pos+1, isSmall, tot, 1);
                ret+=fun(pos+1, 1, tot, 0);
            }
        }
        else{
            ret+=fun(pos+1, isSmall, tot, 0);
        }
    }
    return ret;
}
int main()
{
    int tc,cs=1,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=31; i>=0; i--){
            arr[i] = n%2;
            n/=2;
        }
        memset(dp,-1,sizeof dp);
        printf("Case %d: %lld\n", cs++, fun(0, 0, 0, 0));
    }
    return 0;
}
/**
7 0 6
15
20
21
22
2147483647
*/
