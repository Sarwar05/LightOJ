#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long int tc,x1,y1,x2,y2;cin>>tc;
    for(int t=1; t<=tc; t++){
        cin>>x1>>y1>>x2>>y2;
        long int p = (abs(x1-x2)+abs(y1-y2));
        printf("Case %d: ",t);
        if(abs(x1-x2) == abs(y1-y2))
            cout<<1<<endl;
        else if(p%2==0)
            cout<<2<<endl;
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}
 