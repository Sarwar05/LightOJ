#include<iostream>
#include<cstdio>
using namespace std;
bool isPal()
{
    long long int num,n,temp = 0;
    scanf("%lld",&num);
    n = num;
    while(num!=0){
        int x = num%10;
        num/=10;
        temp = temp*10 + x;
    }
    return n == temp;
}
int main()
{
    int tc; scanf("%d",&tc);
    for(int i=1; i<=tc; i++){

        printf("Case %d: ",i);
        isPal() ? printf("Yes\n") : printf("No\n");
    }

    return 0;
}
