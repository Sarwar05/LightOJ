#include<iostream>
using namespace std;
int main()
{
   
    int tc;cin>>tc;
    int x,x1,x2,y,y1,y2,n;
    for(int t=1; t<=tc; t++){
        cout<<"Case "<<t<<":"<<endl;
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        while(n--){
            cin>>x>>y;
            if((x>=x1 && x<=x2) && (y>=y1 && y<=y2))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
 
    return 0;
}
