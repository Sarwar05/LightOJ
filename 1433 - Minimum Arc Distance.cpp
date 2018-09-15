#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    double ox,oy,ax,ay,bx,by,a,b,o, theta,r;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);
        o = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
        a = (ox-bx)*(ox-bx) + (oy-by)*(oy-by);
        b = (ax-ox)*(ax-ox) + (ay-oy)*(ay-oy);
        r = sqrt(a);
        theta = (a+b-o)/(2.0*sqrt(a)*sqrt(b));
        if(theta>1) theta = 1;
        if(theta<-1) theta = -1;
        theta = acos(theta);
        if(ax==bx && ay==by) theta = 0;
        printf("Case %d: %.10f\n", cs,theta*r);
    }
    return 0;
}
