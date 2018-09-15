#include<iostream>
#include<cstdio>
#include<cmath>
#define pi  2*acos(0.0);
using namespace std;
int main()
{
    int test;double radius,square,circle,ans;
    cin>>test;
    for(int t=1; t<= test; t++){
        cin>>radius;
        circle = pow(radius,2);
        circle *=pi;
        square = (radius *2)*(radius *2);
        ans = square - circle;
        printf("Case %d: %.2f\n",t,ans);
    }
    return 0;
}
