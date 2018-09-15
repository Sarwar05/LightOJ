#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
char pattern[mx], text[mx];
int lps[mx];
int len_t, len_p,tc;
void buildLPS()
{
    int i=0,j=1;
    lps[0] = 0;
    while(j<len_p){
        if(pattern[i]==pattern[j]){
            lps[j] = i+1;
            i++;
            j++;
        }
        else{
            if(i!=0){
                i = lps[i-1];
            }
            else{
                lps[j] = 0;
                j++;
            }
        }
    }
}
int KMPsearch()
{
    int ret = 0;
    int t=0, p=0;
    while(t<len_t){
        if(pattern[p]==text[t]){
            t++;
            p++;
        }
        else{
            if(p != 0){
                p = lps[p-1];
            }
            else{
                t++;
            }
        }
        if(p == len_p){
            ret++;
            p = lps[p-1];
        }
    }
    return ret;
}
int main()
{
    //freopen("out.txt","w",stdout);
    scanf("%d",&tc);
    for(int t=1; t<=tc ;t++){
        scanf("%s%s",text, pattern);
        len_t = strlen(text);
        len_p = strlen(pattern);
        buildLPS();
        printf("Case %d: %d\n", t, KMPsearch());
    }
}
