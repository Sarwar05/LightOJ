/// http://shoshikkha.com/archives/4108
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,cs=1,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        double pro = 1, ddd=n;
        int ans = 0;
        for(int i=1; (1.0 - pro)<0.5 ; i++){
            pro = pro*( (ddd-i)/ddd );
            ans++;
        }
        printf("Case %d: %d\n",cs++,ans);
    }
}
