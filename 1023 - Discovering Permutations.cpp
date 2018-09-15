#include<bits/stdc++.h>
using namespace std;
int print;
void Permutation(char str[], int len, char out[], bool used[], int pos)
{
    if(print<=0)
        return;
    if(pos == len){
        printf("%s\n",out);
        print--;
        return;
    }
    for(int i=0; i<len; i++){
        if(used[i] == true)
            continue;
        else{
            out[pos] = str[i];
            used[i] = true;
            Permutation(str, len,out,used,pos+1);
            used[i] = false;
        }
    }
}
void permute(char s[],int len)
{
    bool used[len];
    for(int i=0; i<len; i++) used[i] = false;
    char out[len+5];
    out[len] = '\0';
    Permutation(s,len,out,used,0);
}

int main()
{
    //freopen("out.txt","w",stdout);
    int tc,n;char s[30];
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&print);
        for(int i=0; i<n; i++){
            s[i] = ('A'+i);
        }
        printf("Case %d:\n",t);
        permute(s,n);
    }

    return 0;
}

