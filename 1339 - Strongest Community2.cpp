#include<bits/stdc++.h>
using namespace std;
int bsize;
struct Query
{
    int l,r,id;
    bool operator<(const Query& ob) const
    {
        if(l/bsize == ob.l/bsize)
            return r<ob.r;
        return l/bsize < ob.l/bsize;
    }
}query[50002];
int arr[100002], frequency[100002], frequencycounter[100002], ans[50002], answer;
void add(int pos)
{
    int val = arr[pos];
    int f = frequency[val];
    if(f==answer){
        answer++;
    }
    frequency[val]++;
    frequencycounter[f]--;
    frequencycounter[f+1]++;
}
void remove(int pos)
{
    int val = arr[pos];
    int f = frequency[val];
    if(f==answer && frequencycounter[f]==1){
        answer--;
    }
    frequency[val]--;
    frequencycounter[f]--;
    frequencycounter[f-1]++;
}
int main()
{
    int n, tc, cs=1,q,c;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n, &c, &q);
        bsize = sqrt(n)+1;
        for(int i=0; i<n; i++) scanf("%d",&arr[i]);
        for(int i=0;i<q; i++){
            scanf("%d%d",&query[i].l, &query[i].r);
            query[i].l--;
            query[i].r--;
            query[i].id = i;
        }
        sort(query, query+q);
        memset(frequency, 0, sizeof frequency);
        memset(frequencycounter, 0, sizeof frequencycounter);
        answer = 0;
        int currL = 0, currR = -1;
        for(int i=0; i<q; i++){
            int L = query[i].l;
            int R = query[i].r;
            while(currL > L)
                add(--currL);
            while(currR < R)
                add(++currR);
            while(currL < L)
                remove(currL++);
            while(currR > R)
                remove(currR--);
            ans[ query[i].id ] = answer;
        }
        printf("Case %d:\n", cs++);
        for(int i=0; i<q; i++) printf("%d\n", ans[i]);
    }
}
