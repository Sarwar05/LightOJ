#include<bits/stdc++.h>
using namespace std;
int a[202], b[202];
int main()
{
    int tc,cs=1,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        for(int i=1; i<=n; i++) scanf("%d",&b[i]);
        int xxx=0;
        for(int i=1; i<=n; i++){
            int x = b[i]-a[i]-1;
            xxx^=x;
        }
        printf("Case %d: %s\n",cs++, (xxx)?"white wins":"black wins");
    }
    return 0;
}
