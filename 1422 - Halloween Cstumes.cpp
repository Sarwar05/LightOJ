#include<bits/stdc++.h>
using namespace std;
int dp[102][102], arr[102];
int fun(int l, int r)
{
    if(l>r) return 0;
    if(l==r) return 1;
    int& ret = dp[l][r];
    if(ret!=-1) return ret;
    ret = 10000007;
    for(int i=l+1; i<=r; i++){
        if(arr[l]==arr[i])
            ret = min(ret, fun(l, i-1) + fun(i+1, r) );
    }
    ret = min(ret, 1 + fun(l+1,r));
    ret = min(ret, 1 + fun(l,r-1));
    return ret;
}
int compress(int n)
{
    vector<int> v;
    arr[0] = -1;
    for(int i=1; i<=n; i++){
        if(arr[i]!=arr[i-1])
            v.push_back(arr[i]);
    }
    for(int i=0; i<v.size(); i++)
        arr[i+1] = v[i];
    return v.size();
}
int main()
{
    int tc,n,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
        memset(dp, -1, sizeof dp);
        n = compress(n);
        printf("Case %d: %d\n", cs++,fun(1,n));
    }
}