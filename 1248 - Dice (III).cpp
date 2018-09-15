#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,cs=1;
    double n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lf",&n);
        double ans = 0;
        for(int i=1; i<=n; i++){
            ans = ans + ( n/i );
        }
        printf("Case %d: %.10f\n",cs++, ans);
    }
    return 0;
}
