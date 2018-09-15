#include<bits/stdc++.h>
using namespace std;
long long int ncr(int n, int k)
{
    long long ret = 1;
     if ( k > n - k )
        k = n - k;
     for (int i = 0; i < k; ++i){
        ret *= (n - i);
        ret /= (i + 1);
    }

    return ret;
}
int  main()
{
    int tc;
    int n,k;
    long long int ans;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&k);
        ans = 1;
        if(k>n){
            ans = 0;
        }
        else{
            ans*=ncr(n,k);
            for(int i=1; i<=k; i++){
                ans*=(n-i+1);
            }
        }
        printf("Case %d: %lld\n",t,ans);
    }
}
