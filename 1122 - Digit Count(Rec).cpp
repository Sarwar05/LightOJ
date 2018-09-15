#include<bits/stdc++.h>
using namespace std;
int value[12];
int n,m;
int fun(int prev, int taken)
{
    if(taken>=n) return 1;
    int ret = 0;
    for(int i=1; i<=m; i++){
        if(abs(prev-value[i])<=2){
            ret+=fun(value[i],taken+1);
        }
    }
    return ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&m,&n);
        for(int i=1; i<=m; i++){
            scanf("%d",&value[i]);
        }
        int ans  = 0;
        for(int i=1; i<=m; i++){
            ans+=fun(value[i],1);
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
