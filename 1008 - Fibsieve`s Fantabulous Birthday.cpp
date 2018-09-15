#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int tc;cin>>tc;
    long long int n,s,c,a,b;
    int x,y;
    for(int t = 1; t<=tc; t++){
        cin>>n;
        s = sqrt(n);
        if(s*s == n){
            if(n%2==1)
                x=1,y=s;
            else
                x=s,y=1;
        }
        else{
            c = s+1;
            a = s*s,b = c*c;
            if(a%2==0){
                if(n<=a+s)
                    x = c,y=n-a;
                else
                    x = b-n+1,y=c;
            }
            else
                if(n<=a+s)
                    x = n-a,y = c;
                else
                    x = c,y = b-n+1;
        }
 
        cout<<"Case "<<t<<": "<<x<<" "<<y<<endl;;
    }
    return 0;
}