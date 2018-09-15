#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,n;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        int ara[n+1];
        ara[0] = 2;
        for(int i=1; i<=n; i++) scanf("%d",&ara[i]);
        int lie = 0;int d;
        for(int i=1; i<=n; i++){
            d = ara[i]-ara[i-1];
            lie+=(d/5);
            if(d%5 > 0)
                lie++;
        }
        printf("Case %d: %d\n",t,lie);
    }
    return 0;
}
