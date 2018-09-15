#include<bits/stdc++.h>
using namespace std;
int cost[15][15];
int n;
#define inf 1000000009
int setBit(int N, int pos)
{
    return ( N|(1<<pos) );
}
bool onBit(int N, int pos)
{
    return (N&(1<<pos));
}
int dp[(1<<14)+2];
int fun(int mask)
{
    if(mask==((1<<n)-1)) return 0;
    int &ret = dp[mask];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i=0; i<n; i++){
        if(!onBit(mask, i)){
            int pay=cost[i][i];
            for(int j=0; j<n; j++){
                if(onBit(mask,j))
                    pay+=cost[i][j];
            }
            ret = min(ret, pay+fun(setBit(mask,i)));
        }
    }
    return ret;
}
int main()
{
    int tc, cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d",&cost[i][j]);
            }
        }
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", cs++, fun(0));
    }
    return 0;
}
