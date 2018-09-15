#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
ll dp[11][90][2][2];
ll fun(int pos, int tot, int isSmall, int start)
{
    if(pos==v.size()) return (start) ? tot  : 0;
    ll& ret = dp[pos][tot][isSmall][start];
    if(ret!=-1) return ret;
    ret = 0;
    int limit = (isSmall) ? 9 : v[pos];
    ret+=fun(pos+1, tot+start,isSmall || (v[pos]!=0) , start );
    for(int i=1; i<=limit; i++){
        ret+=fun(pos+1, tot, isSmall||(v[pos]>i), 1);
    }
    return ret;
}
ll process(ll num)
{
    if(num<0) return -1;
    if(num==0) return 0;
    v.clear();
    while(num>0){
        v.push_back(num%10);
        num/=10;
    }
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof dp);
    return fun(0,0,0,0);
}
int main()
{
    int tc,cs=1;
    ll a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&a,&b);
        printf("Case %d: %lld\n",cs++,  process(b) - process(a-1) );
    }
    return 0;
}
