#include<bits/stdc++.h>
using namespace std;
#define ll long long
/// ///////////////////////////////////
/// dp(i, j) : Probability of sum at least X with i throws and previous sum of j.
/// ///////////////////////////////////
ll dp[26][152];
int lim;
ll fun(int dice, int sum)
{
    if(dice==0 )
        return (sum>=lim);
    ll& ret = dp[dice][sum];
    if(ret!=-1)
        return ret;
    ret = 0;
    for(int i=1; i<=6; i++)
    {
        ret+=fun(dice-1, sum+i);
    }
    return ret;
}

int main()
{
    int tc,n,x,cs=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&x);
        lim = 0;
        memset(dp, -1, sizeof dp);
        ll q = fun(n,0);
        lim = x;
        memset(dp, -1, sizeof dp);
        ll p = fun(n,0);
        //cout<<p<<" "<<q<<endl;
        printf("Case %d: ",cs++);
        if(p<=0)
            printf("0\n");
        else
        {
            ll gc = __gcd(p,q);
            p/=gc;
            q/=gc;
            if(q==1)
                printf("%lld\n",p);
            else
                printf("%lld/%lld\n",p,q);
        }
    }
    return 0;
}
