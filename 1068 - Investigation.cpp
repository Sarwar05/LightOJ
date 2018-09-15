#include<bits/stdc++.h>
using namespace std;
int k;
int dp[10][81][81][2][2];
vector<int> v;
int fun(int pos, int num, int dig,int isSmall, int start)
{
    if(pos==v.size()) return start&&(num==0 &&dig==0);
    int &ret = dp[pos][num][dig][isSmall][start];
    if(ret!=-1) return ret;
    ret = 0;
    int limit = (isSmall) ? 9 : v[pos];
    ret+=fun(pos+1, (num*10)%k, dig, isSmall || v[pos]!=0 , start);
    for(int i=1; i<=limit; i++){
        ret+=fun(pos+1, ((num*10)+i)%k, (dig+i)%k , isSmall||(i<v[pos]), 1);
    }
    return ret;
}
int solve(int num)
{
    if(k>81) return 0;
    v.clear();
    while(num>0){
        v.push_back(num%10);
        num/=10;
    }
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof dp);
    return fun(0,0,0,0,0);
}
int main()
{
    int tc,cs=1,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&a,&b,&k);
        printf("Case %d: %d\n",cs++, solve(b) - solve(a-1));
    }
    return 0;
}
