#include<bits/stdc++.h>
using namespace std;
int money[102],n;
double prob[102], pro;
double dp[102][10004];
int vis[102][10004], color;
int make;
double fun(int pos, int sum)
{
    if(sum>=make) return 0;
    if(pos>n)return 1000000000;
    if(vis[pos][sum]==color) return dp[pos][sum];
    double ddd = fun(pos+1, sum + money[pos]);
    double ret = min( fun(pos+1, sum) ,  ddd + (1-ddd)*prob[pos] );
    vis[pos][sum] =color;
    return dp[pos][sum] = ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        cin>>pro>>n;
        int lo = 0, hi = 0, mid;
        for(int i=1 ; i<=n; i++){
            cin>>money[i]>>prob[i];
            hi+=money[i];
        }
        int ans = 0;
        while(lo<=hi){
            mid = (lo+hi)/2;
            ++color;
            make = mid;
            double p = fun(1,0);
            if(p<pro){
                ans = max(ans, mid);
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        printf("Case %d: %d\n",cs, ans);
    }
}
