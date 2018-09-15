#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-10
inline double sqr(double x)
{
    return (x*x);
}
int main()
{
    int tc,cs=1;
    double a,b,c,d,D,n,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lf%lf%lf",&a,&b,&c);
        D = sqr(b)-(a*c);
        if(D<=EPS){
            printf("Case %d: -1\n",cs++);
            continue;
        }
        n = (a*c*(b+c))/D;
        m = (a*c*(b+a))/D;
        d = m+n;
        printf("Case %d: %.10f\n",cs++,d);
    }
    return 0;
}
