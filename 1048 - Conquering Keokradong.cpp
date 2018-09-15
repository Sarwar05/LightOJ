#include<bits/stdc++.h>
using namespace std;
#define  vi vector<int>
int check(vi v, int k)
{
    int ck=0, sum=0, i=0;
    while(i<v.size()){
        while(sum+v[i]<=k && i<v.size()){
            sum+=v[i];
            i++;
        }
        if(sum>0)
            ck++;
        else{
            ck=1000000;
            break;
        }
        sum = 0;
    }
    return ck;
}
vi gen(vi v, int k)
{
    int sum=0, i=0; vi ret;
    while(i<v.size()){
        while(sum+v[i]<=k && i<v.size()){
            sum+=v[i];
            i++;
        }
        ret.push_back(sum);
        sum = 0;
    }
    return ret;
}
int main()
{
    int tc,n,k;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%d%d",&n,&k);
        vi arr(n+1);
        for(int i=0; i<=n; i++) scanf("%d",&arr[i]);
        int lo = 1, hi = 10000000, mid;
        int mXn = 100000000, mx2 = 100000000;
        while(lo<=hi){
            mid = (lo+hi)/2;
            int x = check(arr, mid);
            if(x==k+1){
                mXn = min(mXn, mid);
                hi = mid-1;
            }
            else if(x<=k){
                mx2 = min(mx2, mid);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        vi ans;
        if(mXn == 100000000){
            mXn = mx2;
            int rem = k+1;
            for(int i=0; i<arr.size(); i++){
                if(rem == arr.size()-i){
                    while(i<arr.size()){
                        ans.push_back(arr[i]);
                        i++;
                    }
                    break;
                }
                else{
                    int sum = 0;
                    rem--;
                    while(rem != arr.size()-i && sum+arr[i]<=mXn && i<arr.size()){
                        sum+=arr[i];
                        i++;
                    }
                    ans.push_back(sum);
                    i--;
                }
            }
        }
        else
            ans = gen(arr, mXn);
        printf("Case %d: %d\n", cs, mXn);
        for(int i=0; i<ans.size(); i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
