#include<bits/stdc++.h>
using namespace std;
double dp[102];
double arr[102];
int n;
double fun(int pos)
{
    if(pos>n) return 0;
    if(dp[pos]!=-1) return dp[pos];
    double ret = arr[pos];
    for(int i=min(6,n-pos); i>=1; i--){
        ret+=((1.0/min(6,n-pos))*fun(pos+i));
    }
    return dp[pos] = ret;
}
double iter()
{
    dp[n] = arr[n];
    for(int i=n-1; i>=1; i--){
        dp[i] = arr[i];
        double d = 1.0/(n-i);
        for(int j=1; j<=6; j++){
            if(i+j<=n){
                dp[i]+=(d*dp[i+j]);
            }
        }
    }
    return dp[1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        cin>>n;
        for(int i=1; i<=n; i++ ){
            cin>>arr[i];
            dp[i] = -1;
        }
        double ans =  fun(1);
        cout<<"Case "<<cs<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
/// 1 3 3 6 9
