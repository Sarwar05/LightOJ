#include<bits/stdc++.h>
using namespace std;
int dp[(1<<16)+2];
struct Point
{
    int x;
    int y;
}point[17];
int mask[18][18];
bool check(int s,int pos)
{
    return !((bool)(s&(1<<pos)));
}
int Set(int s, int pos)
{
    return (s|(1<<pos));
}
int n;
int fun(int state)
{
    if(state==((1<<n)-1)){
        return 0;
    }
    if(dp[state]!=-1) return dp[state];
    int i,j;
    int ret = 100;
    for( i=0; i<n ; i++){
        if(check(state,i)) break;
    }
    for( j=0 ; j<n; j++){
        if(i!=j && check(state,j)){
            ret = min(ret,1+fun(state|mask[i][j]));
        }
    }
    if(ret==100) ret = 1;
    return dp[state] = ret;
}
void calc()
{
    memset(mask, 0, sizeof(mask));
    int x1,x2,x3,y1,y2,y3;
    for(int i=0; i<n; i++) {
        x1 = point[i].x;
        y1 = point[i].y;
        for(int j=0; j<n; j++) {
            x2 = point[j].x;
            y2 = point[j].y;
            for(int k=0; k<n; k++) {
                x3 = point[k].x;
                y3 = point[k].y;
                if(i!=j && (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))==0){
                    mask[i][j] = Set(mask[i][j], k);
                }

            }
        }
    }
}
int main()
{
    int tc,cs=1,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d%d",&a,&b);
            point[i].x = a;
            point[i].y = b;
        }
        memset(dp,-1,sizeof dp);
        calc();
        int ans = fun(0);
        printf("Case %d: %d\n", cs++,ans);
    }
    return 0;
}
