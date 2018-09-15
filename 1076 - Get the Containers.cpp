#include<bits/stdc++.h>
using namespace std;
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)
typedef vector<int> vi;
typedef long long int ll;
int run(int a[],int n, int m,int cap, int tot)
{
    int x[m]; for(int i=0; i<m; i++) x[i] = cap;
    int j = 0, i=0;
    while(i<n && j<m){
        if(a[i]<=x[j]){
            x[j]-=a[i];
            tot-=a[i];
            j--;
        }
        else i--;
        i++;
        j++;
    }
    if(tot==0) return 0;
    else return -1;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc,n,m;
	cin>>tc;
	for(int t=1; t<=tc; t++){
        cin>>n>>m;
        int arr[n];int ans = 0;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            ans += arr[i];
        }
        int total = ans;
        int low = 0, high = ans;
        while(low<=high){
            int mid = (low + high)/2;
            int x = run(arr,n,m,mid,total);
            if(x==0){
                ans = mid;
                high = mid-1;
            }
            else if(x==-1){
                low = mid+1;
            }
        }
        printf("Case %d: %d\n",t,ans);
	}
	return 0;
}
