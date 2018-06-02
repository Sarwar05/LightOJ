#include<bits/stdc++.h>
using namespace std;
double dp[100001];
vector<int> divisor[100001];
double fun(int num)
{
    if(num==1) return 0;
    if(dp[num]!=-1) return dp[num];
    double ret = 0;
    for(int i=0; i<divisor[num].size(); i++){
        ret+=(1+fun(divisor[num][i]));
    }
    double d = divisor[num].size()+2;
    d = 1.0/(d-1);
    ret = 2.0*d + d*ret;
    return dp[num] = ret;
}
void getDivisor(unsigned int num)
{
    int sq = sqrt(num);
    for(unsigned int i=2; i<=sq; i++){
        if(num%i==0){
            int a = num/i;
            if(a!=i) divisor[num].push_back(i);
            divisor[num].push_back(a);
        }
    }
}
void process()
{
    int cnt=0;
    for(int i=1; i<=100000; i++){
        dp[i] = -1;
        getDivisor(i);
    }
    for(int i=1; i<=100000; i++){
        dp[i] = fun(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    process();
    int tc,n;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        cin>>n;
        cout<<"Case "<<cs<<": "<<fixed<<setprecision(10)<<dp[n]<<endl;
    }
    return 0;
}
