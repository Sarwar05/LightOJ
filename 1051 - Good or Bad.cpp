
#include<bits/stdc++.h>
using namespace std;
string str;
int len;
bool isVowel(char c)
{
    return (c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}
int dp[52][4][6];
#define GOOD 1
#define BAD 2
#define MIXED 3
int fun(int pos, int vow, int cons)
{
    if(vow>=3 || cons>=5) return BAD;
    if(pos==len) return GOOD;
    int &ret = dp[pos][vow][cons];
    if(ret!=-1) return ret;
    if(str[pos]=='?'){
        int ret1 = fun(pos+1, vow+1, 0);
        int ret2 = fun(pos+1, 0, cons+1);
        if(ret1==GOOD && ret2==GOOD) ret = GOOD;
        else if(ret1==BAD && ret2==BAD) ret = BAD;
        else ret = MIXED;
    }
    else if(str[pos]=='A'){
        ret = fun(pos+1, vow+1, 0);
    }
    else{
        ret = fun(pos+1, 0, cons+1);
    }
    return ret;
}
int main()
{
    int tc,cs=1;
    char st[55];
    scanf("%d",&tc);
    while(tc--){
        scanf("%s",st);
        len = strlen(st);
        string tem(st);
        str = tem;
        for(int i=0; i<len; i++){
            if(str[i]=='?') continue;
            if(isVowel(str[i])) str[i] = 'A';
            else str[i] = 'B';
        }
        printf("Case %d: ", cs++);
        memset(dp, -1, sizeof dp);
        int ans = fun(0,0,0);
        if(ans==GOOD) printf("GOOD\n");
        else if(ans==BAD) printf("BAD\n");
        else printf("MIXED\n");
    }
    return 0;
}
