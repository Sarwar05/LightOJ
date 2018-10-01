#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
pair<int, int> input[102];
int dp[102][102][102], limit,n;
/// calculate if it is possible to do all work[(1st+2nd)*m] if we give the
/// all the i'th employee limit times
/**
if xth employee do work for t times, he may use it as follows
            one                 two
            0                   t-0
            input[x].ff         t-input[x].ff
            2*input[x].ff       t-input[x].ff*2
            3*input[x].ff       t-input[x].ff*3
            .                   .
            .                   .
    then hey will handle the rest work to x+1 th person
*/
int fun(int pos, int need1, int need2)
{
    if(need1==0 && need2==0) return 1;
    if(pos>n) return 0;
    int& ret = dp[pos][need1][need2];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=0; i<=need1 && (i*input[pos].ff)<=limit; i++){
        int remain = limit - ((i*input[pos].ff));
        int j = remain/input[pos].ss;
        if(j>need2)j = need2;
        ret+=fun(pos+1, need1-i, need2-j);
    }
    return ret;
}
int main()
{
    int tc,cs=1,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&input[i].ff, &input[i].ss);
        int lo = 0, hi = 50000, mid,ans = 50002;
        /// binary search on time
        while(lo<=hi){
            mid= (lo+hi)/2;
            limit = mid;
            memset(dp, -1, sizeof dp);
            if(fun(1,m,m)){
                ans = min(ans, mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
        printf("Case %d: %d\n",cs++, ans);
    }
}
