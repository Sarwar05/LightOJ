#include<bits/stdc++.h>
using namespace std;
#define mx 1002
int ncr[mx*2][3];
int nCr(int n, int r)
{
    if(r>n) return 0;
    if(r==1) return n;
    if(r==n) return 1;
    if(ncr[n][r]!=-1) return ncr[n][r];
    return ncr[n][r] = nCr(n-1,r) + nCr(n-1, r-1);
}
double dp[mx][mx];
int vis[mx][mx] = {0};
double fun(int tiger, int deer)
{
    if(tiger==0) return 1;
    if(vis[tiger][deer]==1) return dp[tiger][deer];
    vis[tiger][deer] = 1;
    double possible = nCr(tiger+deer+1,2), survive = 0;
    if(tiger>=2){
        survive+= nCr(tiger,2)*fun(tiger-2,deer);
    }
    if(deer>=2){
        possible-= nCr(deer,2);
    }
    if(deer>=1){
        survive+= (nCr(tiger+deer,2)-nCr(tiger,2) - nCr(deer,2))*fun(tiger, deer-1);
        possible-= (nCr(deer+1,2) - nCr(deer,2));
    }
    return dp[tiger][deer] = survive/possible;
}
int main()
{
    memset(ncr, -1, sizeof ncr);
    int tc,cs=1,tiger,deer;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&tiger, &deer);
        double res = 0;
        if(tiger%2==0) res = fun(tiger, deer);
        printf("Case %d: %.6f\n", cs++, res);
    }
}
