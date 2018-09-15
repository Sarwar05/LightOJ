#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,cs=1,m,n,x,a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&m,&n);
        int xxx=0;
        for(int i=1; i<=m; i++){
            x=0;
            for(int j=1; j<=n; j++){
                scanf("%d",&a);
                x+=a;
            }
            xxx^=x;
        }
        printf("Case %d: %s\n",cs++,(xxx)?"Alice":"Bob");
    }
    return 0;
}
