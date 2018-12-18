
#include<bits/stdc++.h>
using namespace std;
#define mx 502
int m,n;
int uranium[mx][mx], radium[mx][mx];
int sum_uranium[mx][mx], sum_radium[mx][mx];
int dp[mx][mx];
int fun(int x, int y)
{
    if(x<1 || y<1) return 0;
    int& ret = dp[x][y];
    if(ret!=-1)  return ret;
    ret = max(ret, sum_uranium[x][y] + fun(x-1,y));
    ret = max(ret, sum_radium[x][y] + fun(x,y-1));
    return ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&m,&n);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                scanf("%d",&uranium[i][j]);
            }
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                scanf("%d",&radium[i][j]);
            }
        }
        memset(sum_uranium, 0, sizeof sum_uranium);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                sum_uranium[i][j] = sum_uranium[i][j-1] + uranium[i][j];
            }
        }
        memset(sum_radium, 0, sizeof sum_radium);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                sum_radium[i][j] = sum_radium[i-1][j] + radium[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", cs++,fun(m,n));
    }
}
