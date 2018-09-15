#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;char c;
    int a;
    char str1[105],str2[105];
    scanf("%d%*c",&tc);
    for(int t=1; t<=tc; t++){
        gets(str1);
        gets(str2);
        vector<char> s1,s2;
        for(int i= strlen(str1)-1; i>=0; i--){
            char c = str1[i];
            if(isalpha(c)){
                c = tolower(c);
                s1.push_back(c);
            }
        }
        for(int i= strlen(str2)-1; i>=0; i--){
            char c = str2[i];
            if(isalpha(c)){
                c = tolower(c);
                s2.push_back(c);
            }
        }
        bool found = true;
        int sz = s1.size();
        if(s2.size()!=sz)
            found = false;
        else{
            sort(s1.begin(),s1.end());
            sort(s2.begin(), s2.end());
            for(int i=0; i<sz; i++){
                if(s1[i] != s2[i]){
                    found = false;
                    break;
                }
            }
        }
        if(found)
            printf("Case %d: Yes\n",t);
        else
            printf("Case %d: No\n",t);
 
    }
    return 0;
}