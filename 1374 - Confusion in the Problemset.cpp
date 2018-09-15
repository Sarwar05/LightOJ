#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int main()
{
    int tc,n,a;
    scanf("%d",&tc);
    for(int cas = 1; cas<=tc; cas++){
        memset(arr, 0, sizeof arr);
        scanf("%d",&n);
        bool ans = true;
        for(int i=0; i<n; i++){
            scanf("%d",&a);
            arr[a]++;
        }
        for(int i=1; i<=n; i++){
            if(arr[i-1]>0)
                arr[i-1]--;
            else if(arr[n-i]>0)
                arr[n-i]--;
            else ans = false;
        }
        printf("Case %d: %s\n", cas, ans ? "yes" : "no");
    }
    return 0;
}
