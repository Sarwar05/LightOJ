#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int tc;cin>>tc;
    for(int t=1; t<= tc; t++){
        printf("Case %d:\n",t);
        string str[1000];
        str[0] = "http://www.lightoj.com/";
        string key,s;
        int current = 0,last = 0;
        while(cin>>key){
            if(key=="QUIT")
                break;
 
            else if(key == "BACK"){
                if(current==0)
                    printf("Ignored\n");
                else{
                    current--;
                    cout<<str[current]<<endl;
                }
            }
 
            else if(key == "FORWARD"){
                if(str[current+1].empty())
                    printf("Ignored\n");
                else{
                    current++;
                    cout<<str[current]<<endl;
 
                }
            }
 
            else if(key == "VISIT"){
                for(int i=current+1; i<=last; i++)
                    str[i] = "";
                cin>>s;
                str[++current] = s;
                cout<<str[current]<<endl;
                last++;
 
            }
        }
    }
    return 0;
}
 