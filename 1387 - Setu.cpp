#include<iostream>
#include<cstdio>
using namespace std;
 
int main()
{
    string str; int n,num;
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;cin>>x;int p=0;int total = 0;
        cout<<"Case "<<i<<":\n";
        while(p<x){
            cin>>str;
            if(str=="donate"){
                cin>>num;
                total+=num;
            }
            else if(str =="report"){
                cout<<total<<endl;
            }
        p++;
        }
    }
 
    return 0;
}