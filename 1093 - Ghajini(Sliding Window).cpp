#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&k);
        int arr[n];
        for(int i=0; i<n; i++) scanf("%d",&arr[i]);
        int ans = -1;
        deque<int> mn(k), mx(k);
        for(int i=0; i<k; i++){
            while(!mn.empty() && arr[mn.back()] >= arr[i])
                mn.pop_back();
            mn.push_back(i);
            while(!mx.empty() && arr[mx.back()] <= arr[i])
                mx.pop_back();
            mx.push_back(i);
        }
        for(int i=k; i<n; i++){
            ans = max(ans, arr[mx.front()]-arr[mn.front()]);
            while(!mn.empty() && mn.front()<=i-k)
                mn.pop_front();
            while(!mx.empty() && mx.front()<=i-k)
                mx.pop_front();
            while(!mn.empty() && arr[mn.back()] >= arr[i])
                mn.pop_back();
            mn.push_back(i);
            while(!mx.empty() && arr[mx.back()] <= arr[i])
                mx.pop_back();
            mx.push_back(i);
        }
        ans = max(ans, mx.front()-mn.front());
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
 
