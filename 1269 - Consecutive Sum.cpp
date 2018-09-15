#include<bits/stdc++.h>
using namespace std;
#define mx 50005
int arr[mx];
struct Node
{
    int value;
    Node* next[2];
    Node()
    {
        value = 0;
        next[0] = next[1] = NULL;
    }
}* root;
void del(Node* curr)
{
    if(curr->next[0]!=NULL)
        del(curr->next[0]);
    if(curr->next[1]!=NULL)
        del(curr->next[1]);
    delete(curr);
}
void insert(int val)
{
    Node* curr = root;
    for(int i=31; i>=0; i--){
        bool bit = val & (1<<i);
        if(curr->next[bit]==NULL)
            curr->next[bit] = new Node();
        curr = curr->next[bit];
    }
    curr->value = val;
}
int mxQuery(int val)
{
    Node* curr = root;
    for(int i=31; i>=0; i--){
        bool bit = val & (1<<i);
        if(curr->next[1-bit]!=NULL)
            curr = curr->next[1-bit];
        else if(curr->next[bit]!=NULL)
            curr = curr->next[bit];
        else break;
    }
    return val^(curr->value);
}
int mnQuery(int val)
{
    Node* curr = root;
    for(int i=31; i>=0; i--){
        bool bit = val & (1<<i);
        if(curr->next[bit]!=NULL)
            curr = curr->next[bit];
        else if(curr->next[1-bit]!=NULL)
            curr = curr->next[1-bit];
        else break;
    }
    return val^(curr->value);
}
void solve(int n)
{
    root = new Node();
    int mxAns = INT_MIN, mnAns = INT_MAX, pre_xor = 0;
    insert(0);
    for(int i=0; i<n; i++){
        pre_xor^=arr[i];
        mnAns = min(mnAns, mnQuery(pre_xor));
        insert(pre_xor);
        mxAns = max(mxAns, mxQuery(pre_xor));
    }
    printf("%d %d\n",mxAns, mnAns);
    del(root);
}
int main()
{
    int tc,cs=1,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&arr[i]);
        }
        printf("Case %d: ",cs++);
        solve(n);
    }
    return 0;
}
