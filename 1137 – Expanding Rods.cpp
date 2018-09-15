#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)

int main()
{
    int tc;
    double l,n,c,L,r,ans=0;
    cin>>tc;
    for(int t=1; t<=tc; t++){
        cin>>l>>n>>c;
        L = (1 + (n*c))*l;
        double lo=0, hi = L, mid;
        for(int i=0; i<=100; i++){
            mid = (lo+hi)/2;
            double ang = acos((mid*mid + mid*mid - l*l)/(2.0*mid*mid));
            double S = mid*ang;
            if(S>=L )
                lo = mid;
            else hi = mid;
        }
        cout<<"r = "<<mid<<endl;
        r = mid;
        ans = r - (sqrt(r*r - (l/2.0)*(l/2.0)));
        printf("Case %d: %.10f\n",t,ans);
    }
    return 0;
}
