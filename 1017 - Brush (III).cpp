#include<bits/stdc++.h>
using namespace std;
int w,n;
vector<int> point;
int dp[102][102];
int fun(int pos, int rem)
{
    if(pos>=n || rem<=0) return 0;
    if(dp[pos][rem]!=-1) return dp[pos][rem];
    int x = upper_bound(point.begin(),point.end(),point[pos]+w) - point.begin()-1;
    int ret1 = (x-pos+1),ret2=0;
    //cout<<point[pos]<<" to "<<point[pos]+w<<" = " <<x<<endl;
    ret1 += fun(x+1,rem-1);
    ret2 += fun(pos+1,rem);
    return dp[pos][rem] = max(ret1,ret2);
}
int main()
{
    int tc,k,x,y,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&w,&k);
        point.clear();
        for(int i=1; i<=n; i++){
            scanf("%d%d",&x,&y);
            point.push_back(y);
        }
        sort(point.begin(),point.end());
//        for(int x:point) cout<<x<<" ";
//        cout<<endl;
        memset(dp,-1,sizeof dp);
        int ans = fun(0,k);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
