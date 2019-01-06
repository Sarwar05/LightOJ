#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
ll dp[18][2][2][2][18];
ll fun(int pos=0,int isStart = 0, int isSmall=0, int isBig=0, int bpos=17)
{
    if(pos>bpos)
    {
        if(isBig==1 && isSmall==0) return 0;
        return 1;
    }
    ll& ret = dp[pos][isStart][isSmall][isBig][bpos];
    if(ret!=-1) return ret;
    ret = 0;
    int lim = (isSmall) ?  9 : v[pos];
    for(int i=0; i<=lim; i++){
        if(isStart || i>0){
            if(pos==bpos || i==v[bpos]){ /// can't change isBig
                ret+=fun(pos+1, 1, isSmall||(i<v[pos]), isBig, bpos-1);
            }
            else{
                ret+=fun(pos+1, 1, isSmall||(i<v[pos]), i>v[bpos], bpos-1);
            }
        }
        else{/// still putting 0, it cant change bpos
            ret+=fun(pos+1,0, isSmall||(i<v[pos]), 0, bpos);
        }
    }
    return ret;
}
ll solve(ll num)
{
    if(num<0) return 0;
    v.clear();
    for(int i=1; i<=18; i++){
        v.push_back(num%10);
        num/=10;
    }
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof dp);
    return fun();
}
int main()
{
    int tc,cs=1;
    ll a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&a,&b);
        if(a>b) swap(a,b);
        a = solve(a-1);
        b = solve(b);
        printf("Case %d: %lld\n",cs++, b-a);
    }
}
