#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    double a,b,x, lo, hi, theta,c,y;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%lf : %lf",&a,&b);
        y = sqrt(a*a + b*b);
        theta = asin(b/y);
        lo = 0, hi = 1000;
        for(int i=1; i<=34; i++){
            x = (lo+hi)/2;
            c = sqrt(a*x*a*x + b*x*b*x)*theta;
            if(c+(a*x) >200)
                hi = x;
            else lo = x;
        }
        printf("Case %d: %.10f %.10f\n",cs,a*x, b*x);
    }
    return 0;
}
