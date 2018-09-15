#include<iostream>
#include<cstdio>
#include<cmath>
 
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int t=1; t<= test; t++){
        long long int ans, m,n;
        cin>>m>>n;
        ans = (n*m)/2;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}