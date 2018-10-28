#include<bits/stdc++.h>
using namespace std;
double dp[502][502][2];
int vis[502][502][2] = {0}, ok;
double fun(int red, int blue, int  turn)
{
    turn%=2;
    if(turn==1 && blue ==0) return 0;
    if(blue+red==1 ){
        if(blue==1) return 1;
        else return 0;
    }
    if(vis[red][blue][turn]==1) return dp[red][blue][turn];
    vis[red][blue][turn] =1;
    double& ret = dp[red][blue][turn];
    ret = 0;
    if(turn==0){
        if(red>0)ret += (red*1.0/(red+blue))*fun(red-1, blue, turn+1) ;
        if(blue>0) ret+= (blue*1.0/(red+blue))*fun(red, blue-1, turn+1);
    }
    else{
        ret = fun(red, blue-1,turn+1);
    }
    return ret;
}
int main()
{
    int tc,r,b;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%d%d",&r,&b);
        printf("Case %d: %.8f\n",cs, fun(r,b,0));
    }
}
