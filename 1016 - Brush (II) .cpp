#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,w,a,n,b;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&w);
        int v[n];
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a,&b);
            v[i-1] = b;
        }
        sort(v, v+n);
        int mov = 0;
        for(int i=0; i<n;){
            int hi = v[i]+w;
            while(v[i]<=hi && i<n){
                i++;
            }
            mov++;
        }
        printf("Case %d: %d\n",t,mov);
    }

    return 0;
}
