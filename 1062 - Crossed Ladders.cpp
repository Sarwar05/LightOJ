#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc,cs=1;
    double x,y,c,p,q,lo,hi,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lf%lf%lf",&x,&y,&c);
        lo = 0, hi = max(x,y);
        for(int i=1; i<=100; i++){
            m = (lo + hi)/2;
            p = sqrt( x*x - m*m );
            q = sqrt( y*y - m*m);

            if((1.0/c) > (1.0/p) + (1.0/q)){
                lo = m;
            }
            else{
                hi = m;
            }
        }
        printf("Case %d: %.10f\n", cs++, m);
    }
    return 0;
}
