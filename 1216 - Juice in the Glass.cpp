#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main()
{
    int tc;
    scanf("%d",&tc);
    double r1,r2,h,p,r,v;
    for(int cs=1; cs<=tc; cs++){
       scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
       r = r2 + (r1-r2)*(p/h);
       v = (1.0/3.0)*pi*p*(r*r + r*r2 + r2*r2);
       printf("Case %d: %.10f\n", cs, v);
    }
    return 0;
}

