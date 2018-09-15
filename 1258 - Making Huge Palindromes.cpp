#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
char pattern[mx], text[mx];
int lps[mx];
int len,tc;
void buildLPS()
{
    int i=0,j=1;
    lps[0] = 0;
    while(j<len){
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
    int t=0, p=0;
    while(t<len){
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
    }
    return p;
}

int main()
{
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%s", text);
        len = strlen(text);
        strcpy(pattern, text);
        len = strlen(text);
        reverse(pattern, pattern+len);
        buildLPS();
        int match = KMPsearch();
        printf("Case %d: %d\n",t, len*2 - match);
    }

    return 0;
}
//*
