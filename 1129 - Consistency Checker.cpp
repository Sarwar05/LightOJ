#include<bits/stdc++.h>
using namespace std;
bool ans;
struct node
{
    bool end;
    node* next[10];
    node()
    {
        end = false;
        for(int i=0; i<10; i++)
            next[i] = NULL;
    }
}* root;
void insert(char* str, int len)
{
    node* curr = root;
    for(int i=0; i<len; i++){
        int id = str[i] - '0';
        if(!ans && curr->end)
            ans = true;
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    if(!ans && curr->end)
            ans = true;
    if(!ans){
        for(int i=0; i<10; i++){
            if(curr->next[i]!=NULL){
                ans = true;
                break;
            }
        }
    }
    curr->end = true;
}
void del(node* curr)
{
    for(int i=0; i<10; i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}
int main()
{
    int tc, cs=1,n;
    char str[11];
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        ans = false;
        root = new node();
        while(n--){
            scanf("%s", str);
            insert(str, strlen(str));
        }
        printf("Case %d: ", cs++);
        if(ans) printf("NO\n");
        else printf("YES\n");
        del(root);
    }
}