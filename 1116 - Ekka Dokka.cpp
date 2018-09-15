#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int test;long long int a,b,c,x;
    cin>>test;
    for(int t=1; t<= test; t++){
        cin>>a;
        if(a%2==1)
            printf("Case %d: Impossible\n",t);
        else{
            x = a/3;
            for(long long int i=2; i<=x ;i+=2){
                long long int temp = a/i;
                    if(temp*i==a &&(i%2==0 && temp%2==1)){
                        b=i;c=temp;
                        break;
                    }
            }
            printf("Case %d: %lld %lld\n",t,c,b);
        }
    }
    return 0;
}
 