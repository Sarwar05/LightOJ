#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main()
{
    int tc;
    scanf("%d",&tc);
    double R,x,n;
    for(int cs=1; cs<=tc; cs++){
       scanf("%lf%lf",&R,&n) ;
       x = sin(pi/n);
        printf("Case %d: %.10f\n", cs, (x*R/(x+1)));
    }
    return 0;
}
