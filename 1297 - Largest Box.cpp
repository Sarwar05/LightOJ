#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,cs=1;
    double l,w;
    cin>>tc;
    while(tc--){
        cin>>l>>w;
        double lo = 0, hi = (min(l,w))/2.0;
        //cout<<"lo hi "<<lo<<" "<<hi<<endl;
        for(int i=1; i<=50; i++){
            double mid1 = lo + (hi-lo)/3;
            double mid2 = hi - (hi-lo)/3;
            //cout<<"mid: "<<mid1<<" "<<mid2<<endl;
            double area1 = (w-(2*mid1))*(l-(2*mid1))*mid1;
            double area2 = (w-(2*mid2))*(l-(2*mid2))*mid2;
            //cout<<"area: "<<area1<<" "<<area2<<endl;
            if(area1<0){
                hi = mid1;
                continue;
            }
            else if(area2<0){
                hi = mid2;
                continue;
            }

            if(area1>area2) hi = mid2;
            else lo = mid1;
        }
        //cout<<"final mid: "<<lo<<" "<<hi<<endl;
        double x = (lo+hi)/2.0;
        double area = (w-(2*x))*(l-(2*x))*x;
        cout<<"Case "<<cs++<<": "<<fixed<<setprecision(10)<<area<<endl;
    }
    return 0;
}
