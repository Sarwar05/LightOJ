#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc; scanf("%d",&tc);
    double v1,v2,v3,a1,a2,t1,t2,s1,s2,d,bird;
    for(int t=1; t<=tc; t++){
        cin>>v1>>v2>>v3>>a1>>a2;
        s1 = (v1*v1)/(2.0*a1);
        s2 = (v2*v2)/(2.0*a2);
        d = s1+s2;
        t1 = v1/a1;
        t2 = v2/a2;
        t1 = max(t1,t2);
        bird = t1*v3;
        printf("Case %d: %.10lf %.10lf\n",t,d,bird);
    }
 
    return 0;
}