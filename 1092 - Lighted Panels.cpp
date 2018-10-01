#include<bits/stdc++.h>
using namespace std;
int dp[9][(1<<8)+2][(1<<8)+2];
/// pos, prev_row, curr_row
int status[9],r,c;
/// initial state of i'th row
char str[10];
#define inf 100000008
int fun(int pos, int prev, int curr)
{
    if(pos>=r){
        /// all row is done & previous state of our last row is on
        if(prev == (1<<c)-1) return 0;
        else return inf;
    }
    int& ret = dp[pos][prev][curr];
    if(ret!=-1) return ret;
    ret = inf;
    for(int i=0; i<(1<<c); i++){
        /// generate all possible toggle of current row
        /// bit 1 means toggle it, 0 means don't toggle it
        int cnt = 0;/// count number of toggle
        int last = prev, now = curr, nxt = status[pos+1];

        for(int j=0; j<c; j++){
            if(!(i&(1<<j))) continue; /// don't toggle the j'th bit, coz' it is 0

            cnt++;

            int val = 1<<j;
            last^=val, now^=val, nxt^=val;/// toggle current row

            if(j+1 < c){
                val = 1<<(j+1);
                last^=val, now^=val, nxt^=val;/// toggle next row
            }

            if(j-1 >= 0){
                val = 1<<(j-1);
                last^=val, now^=val, nxt^=val;/// toggle previous row
            }
        }
        /// if current row = 0, we can fix it from next row
        /// but if current row>1 if previous row if okay then we go to fix next
        /// because from next row we can fix current but not previos
        if(pos==0 || (1<<c)-1 == last)/// proceed to next row if current position is 0 or previous row is on
            ret = min(ret, cnt + fun(pos+1, now, nxt));
    }
    return ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&r,&c);
        for(int i=0; i<r; i++){
            scanf("%s",str);
            int mask = 0;
            for(int j=0; j<c; j++){
                if(str[j]=='*') mask|=(1<<j);
            }
            status[i] = mask;/// given status of current row
        }
        memset(dp, -1, sizeof dp);
        int ans = fun(0,0,status[0]);
        printf("Case %d: ", cs++);
        if(ans==inf) printf("impossible\n");
        else printf("%d\n",ans);
    }
}
