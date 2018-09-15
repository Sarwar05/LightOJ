#include<bits/stdc++.h>
using namespace std;
#define inf 10000007
int damage[16][16], power[16];
char str[18];
int setBit(int N, int pos)
{
    return N = N|(1<<pos);
}
bool isZero(int N, int pos)
{
    bool ret = N&(1<<pos);
    return !ret;
}
int dp[(1<<16)+2];
int n;
int fun(int mask)
{
    if(mask == (1<<n)-1) return 0;
    int& ret = dp[mask];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i=0; i<n; i++){
        if(isZero(mask, i)){
            int nm = setBit(mask, i);
            ret = min(ret, power[i] + fun(nm));
            for(int j=0; j<n; j++){
                if(!isZero(mask, j)){
                    int po = damage[j][i];
                    if(po>0){
                        int shot = power[i]/po;
                        if(power[i]%po) shot++;
                        ret = min(ret, shot + fun(nm));
                    }
                }
            }
        }
    }
    return ret;
}
int main()
{
    int tc, cs=1;
    scanf("%d",&tc);
    while(tc--){
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&power[i]);
        }
        for(int i=0; i<n;i++){
            scanf("%s",str);
            for(int j=0; j<n; j++){
                damage[i][j] = str[j]-'0';
            }
        }
        printf("Case %d: %d\n",cs++, fun(0));
    }
    return 0;
}
/**
2 3
10 10 10
010
100
111
3
3 5 7
030
500
007
*/
