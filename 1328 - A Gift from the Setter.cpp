#include<bits/stdc++.h>
using namespace std;
#define mod 1000007
#define mx 100004
long long arr[mx],cum[mx];
int main()
{
    int tc,cs=1,k,c,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&k,&c,&n);
        scanf("%lld",&arr[0]);
        for(int i=1; i<n; i++){
            arr[i] = (k * arr[i-1] + c) % 1000007;
        }
        cum[n] = 0;
        long long ans = 0;
        sort(arr,arr+n);
        for(int i=n-1; i>=0; i--) cum[i] = cum[i+1] + arr[i];
        for(int i=0; i<n; i++){
            ans = ans + cum[i+1] - (n-1-i)*arr[i];
        }
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}