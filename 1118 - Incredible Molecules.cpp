#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define EPS 1e-10
#define inf 10000000000000
double angel(double a, double b, double c)
{
    double ang = (b*b + c*c - a*a)/(2.0*b*c);
    double ret = acos(ang);
    return ret;
}
double arc_area(double r, double theta)
{
    return (0.5*theta*r*r);
}
double tri_area(double a, double b, double c)
{
    double s = (a+b+c)/2;
    double ret = sqrt(s*(s-a)*(s-b)*(s-c));
    return ret;
}
int main()
{
    double x1,x2,y1,y2,r1,r2, ans;
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
        double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        ans = 0;
        if(dist<=fabs(r1-r2))/// totally inside
        {
            ans = PI*pow(min(r1,r2),2);
        }
        else if(dist<(r1+r2))/// inside
        {
 
            if(dist>=r1 && dist>=r2) /// center outside of both
            {
                double area = tri_area(r1,r2,dist);
                double h = 2*((2*area)/dist);
                double theta1 = angel(h,r1,r1);
                double theta2 = angel(h,r2,r2);
                ans+=(arc_area(r1,theta1) - tri_area(r1,r1,h));
                ans+=(arc_area(r2,theta2) - tri_area(r2,r2,h));
            }
//            else if(dist>=r1){
//
//            }
//            else if(dist>=r2){
//
//            }
            else /// center inside
            {
                double area = tri_area(r1,r2,dist);
                double h = 2*((2*area)/dist);
                double area1 = PI*r1*r1;
                double area2 = PI*r2*r2;
                double theta1 = angel(h,r1,r1);
                double theta2 = angel(h,r2,r2);
                double arc1 = arc_area(r1,theta1);
                double arc2 = arc_area(r2,theta2);
                double tri1 = tri_area(r1,r1,h);
                double tri2 = tri_area(r2,r2,h);
                double l1 = sqrt(pow(r1,2)-pow(dist/2.0, 2.0));
                double l2 = sqrt(pow(r2,2)-pow(dist/2.0, 2.0));
                if(dist/2.0 > r1) l1 = 0;
                if(dist/2.0 > r2) l2 = 0;
                if((l1>=dist || l2>=dist) && l1!=l2)/// concave
                {
                    if(r1>=r2)
                    {
                        ans = area2 - arc2 + tri2 + (arc1 - tri1);
                    }
                    else
                    {
                        ans = area1 - arc1 + tri1 + (arc2 - tri2);
                    }
                }
                else{/// convex
                    ans = arc2 + arc1-tri1-tri2;
                }
            }
 
        }
        printf("Case %d: %.10f\n",cs++,ans);
    }
    return 0;
}
 