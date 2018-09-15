#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int tc;cin>>tc;
    long long int x,y,a,b,ans;
    for(int t=1; t<= tc; t++){
        cin>>x>>y;
 
        if(x%3 == 0 || x%3 == 1)
            a = ((int)(x/3))*2;
        else
            a = (x/3)*2 + 1;
 
        if(y%3 == 0 || y%3 == 1)
            b = ((int)(y/3))*2;
        else
            b =  (y/3)*2 + 1;
 
        ans = b-a+1;
        if((y%3 == 1 && x%3 == 1) || (y%3 != 1 && x%3 == 1))
            ans --;
 
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
 
    return 0;
}
 