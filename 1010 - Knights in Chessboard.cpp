#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    int tc,n,m;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&m);
        int ans;
        ans = (((n/2)*(m/2)) + (n-n/2)*(m-m/2));
        if(m>n) swap(m,n);
        if(n==1 || m==1)
            ans = max(n,m);
        else if(m==2){
            if(n%4 == 1)
                ans = n+1;
            else
                ans = 4*((n+3)/4);
        }
        printf("Case %d: %d\n",t,ans);
    }

}
