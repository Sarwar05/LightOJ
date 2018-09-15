#include<bits/stdc++.h>
using namespace std;
int grundy[10004];
int getGrundy(int n)
{
    if(n<=2) return 0;
    if(grundy[n]!=-1) return grundy[n];
    set<int> st;
    for(int i=1; ; i++){
        int j = n-i;
        if(i>=j) break;
        int a = getGrundy(i);
        int b = getGrundy(j);
        st.insert(a^b);
    }
    int val = 0;
    set<int>::iterator it = st.begin();
    while(it!=st.end()){
        if((*it)!=val) return val;
        val++;
        it++;
    }
    return val;
}
int main()
{
    memset(grundy, -1, sizeof grundy);
    for(int i=1; i<=10000; i++){
        grundy[i] = getGrundy(i);
    }
    int tc,n,a,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        int xxx=0;
        while(n--){
            scanf("%d",&a);
            xxx^=grundy[a];
        }
        printf("Case %d: %s\n",cs++,(xxx)?"Alice":"Bob");
    }
    return 0;
}
