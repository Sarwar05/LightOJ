#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int cnt[5];
    node* next[5];
    node()
    {
        for(int i=0; i<4; i++){
            cnt[i] = 0;
            next[i] = NULL;
        }
    }
}* root;
map<char, int> mp;
ll insert(char* str, int len)
{
    node* curr = root;
    ll ret = 0, tem;
    for(int i=0; i<len; i++){
        int id = mp[str[i]];
        curr->cnt[id]++;
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        tem  = curr->cnt[id];
        tem = tem *(i+1);
        ret = max(ret,tem);
        curr = curr->next[id];
    }
    return ret;
}
void del(node* curr)
{
    for(int i=0; i<4; i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}
int main()
{
    mp['A'] = 0;mp['C'] = 1;mp['G'] = 2;mp['T'] = 3;
    int tc, cs=1, n;
    char str[55];
    scanf("%d", &tc);
    while(tc--){
        root = new node();
        scanf("%d", &n);
        ll ans = 0;
        while(n--){
            scanf("%s", str);
            ans = max(ans, insert(str, strlen(str)));
        }
        printf("Case %d: %lld\n", cs++, ans);
        del(root);
    }
    return 0;
}
