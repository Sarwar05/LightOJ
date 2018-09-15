
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int tc;cin>>tc;
    for(int t=1; t<=tc; t++){
        cout<<"Case "<<t<<":"<<endl;
        deque<int> dq;
        int max,op,a;string s;
        cin>>max>>op; int count = 0;
        for(int i=1; i<=op; i++){
            cin>>s;
            if(s == "pushLeft"){
                cin>>a;
                if(count == max)
                    cout<<"The queue is full"<<endl;
                else{
                    count++;
                    dq.push_front(a);
                    cout<<"Pushed in left: "<<a<<endl;
                }
            }
            else if(s == "pushRight"){
                cin>>a;
                if(count == max)
                    cout<<"The queue is full"<<endl;
                else{
                    count++;
                    dq.push_back(a);
                    cout<<"Pushed in right: "<<a<<endl;
                }
            }
            else if(s == "popLeft"){
                if(count == 0)
                    cout<<"The queue is empty"<<endl;
                else{
                    count--;
                    a = dq.front();
                    dq.pop_front();
                    cout<<"Popped from left: "<<a<<endl;
                }
            }
            else if(s == "popRight"){
                if(count == 0)
                    cout<<"The queue is empty"<<endl;
                else{
                    count--;
                    a = dq.back();
                    dq.pop_back();
                    cout<<"Popped from right: "<<a<<endl;
                }
            }
        }
    }
    return 0;
}