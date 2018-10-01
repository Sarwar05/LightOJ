#include<bits/stdc++.h>
using namespace std;
map<char, int> occ;
map<char, int> :: iterator it;
#define ll long long
int len;
ll fact[22];
void pre()
{
    fact[0] = 1;
    for(int i=1; i<=20; i++)
        fact[i] = i*fact[i-1];
}
ll calcPossible()
{
    ll ret = fact[len];
    for(it = occ.begin(); it!=occ.end(); it++)
        ret/=fact[ it->second ];
    return ret;
}
void solve(ll nth)
{
    string ans = "";
    while(len--){
        ll total = 0;
        for(char ch = 'a'; ch<='z' ;ch++){
            if(occ.find(ch)==occ.end()) continue;
            occ[ch]--;
            ll got = calcPossible();
            if(total + got>=nth){
                nth-=total;
                ans+=ch;
                if(occ[ch]==0) occ.erase(ch);
                break;
            }
            else{
                total+=got;
                occ[ch]++;
            }
        }
    }
    printf("%s\n", ans.c_str());
}
int main()
{
    pre();
    char str[22];
    int tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        occ.clear();
        scanf("%s",str);
        len = strlen(str);
        for(int i=0; i<len; i++)
            occ[str[i]]++;
        ll nth;scanf("%lld",&nth);
        ll mxpossible = calcPossible();
        printf("Case %d: ",cs++);
        if(nth>mxpossible) printf("Impossible\n");
        else solve(nth);
    }
}
