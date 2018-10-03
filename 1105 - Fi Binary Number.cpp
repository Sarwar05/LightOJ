#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 43
int ans[mx];
int dp[mx][2][2];
int fun(int pos, int prev, int start)
{
    if(pos<0) return start;
    int&ret = dp[pos][prev][start];
    if(ret!=-1) return ret;
    ret = 0;
    ret+=fun(pos-1, 0, start);
    if(prev==0) ret+=fun(pos-1,1,1);
    return ret;
}
int main()
{
    memset(dp, -1, sizeof dp);
    //fun(42,0,0);
    int tc,n,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        printf("Case %d: ",cs++);
        memset(ans, -1, sizeof ans);
        int prev = 0;
        for(int i=43; i>=1; i--){
            int r0 = fun(i-1, 0, 1);
			int r1 = fun(i-1,1,1);
			if(r0>n){
				ans[i] = 0;
			}
			else{
				n-=r0;
				ans[i] = 1;
			}
        }
		ans[0] = n;
        for(int i=43; i>=0; i--){
            if(ans[i]==0)
                ans[i] = -1;
            else break;
        }
        for(int i=43; i>=0; i--){
            if(ans[i]!=-1)
                printf("%d",ans[i]);
        }
        puts("");
    }
}
