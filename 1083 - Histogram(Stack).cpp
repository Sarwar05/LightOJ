#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
    //freopen("out.txt","w",stdout);
    int tc,n;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        int ara[n];
        for(int i=0; i<n; i++) scanf("%d",&ara[i]);
        ll area = 0;
        ll temp=0;
        stack<int> st;
        for(int i=0; i<n; ){
            if(st.empty() || ara[st.top()] <= ara[i] ){
                st.push(i++);
            }
            else{
                int a = st.top();
                st.pop();
                if(st.empty()){
                    temp = ara[a]*i;
                }
                else{
                    temp = ara[a]*(i-st.top()-1);
                }
                if(temp>area) area = temp;
            }
        }
        while(!st.empty()){
            int a = st.top();
            st.pop();
            if(st.empty()){
                temp = ara[a]*n;               
            }
            else{
                temp = ara[a]*(n-st.top()-1);
            }
            if(temp>area) area = temp;
        }
        printf("Case %d: %lld\n",t,area);
    }
    return 0;
}
 