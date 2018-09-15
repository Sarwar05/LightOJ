#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll tc,cs=1,t,n,c;
    cin>>tc;
    while(tc--){
        cin>>n>>c;
        if(n==0) t = 0;
        else{
            int lo = 0,hi = h;
            for(int i=1; i<=100; i++){
                ll mid1 = lo + (hi-lo)/3;
                ll mid2 = hi - (hi-lo)/3;
                //cout<<"mid: "<<mid1<<" "<<mid2<<endl;
                ll profit1 = mid1 * (c - (n*mid1));
                ll profit2 = mid2 * (c - (n*mid2));
                //cout<<"profit: "<<profit1<<" "<<profit2<<endl;
                if(profit1<0){
                    hi = mid1;
                    continue;
                }
                else if(profit2<0){
                    hi = mid2;
                    continue;
                }
                if(profit1<profit2){
                    lo = mid1;
                }
                else {
                    hi = mid2;
                }
            }
            t = (lo+hi)/2;
        }
        printf("Case %lld: %lld\n",cs++, t);
    }
    return 0;
}
