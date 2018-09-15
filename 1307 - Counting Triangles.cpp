#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,cs=1,n, l,r,x,y;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        vector<int> arr(n);
        for(int i=0; i<n; i++) scanf("%d",&arr[i]);
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                l = arr[j]-arr[i]+1;
                r = arr[i]+arr[j];
                x = lower_bound(arr.begin()+j+1, arr.end(), l) - arr.begin();
                y = lower_bound(arr.begin()+j+1, arr.end(), r) - arr.begin()-1;
                ans = ans + (y-x+1);
            }
        }
        printf("Case %d: %d\n",cs++, ans);
    }
    return 0;
}
