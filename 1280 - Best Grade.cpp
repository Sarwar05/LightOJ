#include<bits/stdc++.h>
using namespace std;
#define mx 20004
struct Marks
{
    double got;
    double total;
}mark[mx];
double Mid;
bool comp(Marks a, Marks b)
{
    return (a.got - Mid*a.total)  > (b.got - Mid*b.total);
}
bool check(double mid, int n, int use)
{
    Mid = mid/100.0;
    sort(mark+1, mark+1+n, comp);
    double Got = 0, Total = 0;
    for(int i=1; i<=use; i++){
        Got+=mark[i].got;
        Total+=mark[i].total;
    }
    double avg = (Got/Total)*100;
    return avg >= mid;
}
int main()
{
    int tc,n,cs=1, use;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&use);
        use = n-use;
        for(int i=1; i<=n; i++)
            scanf("%lf%lf",&mark[i].got, &mark[i].total);
        double lo = 0, hi = 100, mid,ans = 0;
        for(int i=1; i<=25; i++){
            mid = (lo+hi)/2.0;
            if(check(mid, n, use)){
                lo = mid;
                ans = max(ans, mid);
            }
            else hi = mid;
        }
        printf("Case %d: %.10f\n", cs++,ans);
    }
}
/**
(p1 + p2 + p3)/(m1 + m2 + m3) = ans;
p1 + p2 + p3 = ans*m1 + ans*m2 + ans*m3;
p1-ans*m1 + p2-ans*m2 + ans*m3 = 0
*/
