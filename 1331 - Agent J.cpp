#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    double r1,r2,r3, ans,a,b,c,A,B,C,s, area;
    scanf("%d",&tc);
    for(int cs = 1; cs<=tc; cs++){
        scanf("%lf%lf%lf",&r1, &r2,&r3);
        a = r2 + r3;
        b = r1 + r3;
        c = r1 + r2;
        A = acos((b*b + c*c - a*a)/(2.0*b*c));
        B = acos((a*a + c*c - b*b)/(2.0*a*c));
        C = acos((a*a + b*b - c*c)/(2.0*a*b));
        s = (a+b+c)/2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        ans= area - (0.5*A*r1*r1) -  (0.5*B*r2*r2) -  (0.5*C*r3*r3);
        printf("Case %d: %.10f\n",cs,  ans);
    }
    return 0;
}

