#include<bits/stdc++.h>
using namespace std;
#define mx 1003
int level[mx];
vector<int>pdiv[mx];
int ara[mx];
vector<int > prime;
void sieve()
{
    memset(ara, 0, sizeof ara);
    for(int i=2; i<mx; i++){
        if(ara[i]==0){
            prime.push_back(i);
            for(int j = i*i; j<mx; j+=i){
                ara[j] = 1;
            }
        }
    }
}
void getPdiv()
{
    sieve();
    int sz = prime.size();
    for(int i=0; i<sz; i++){
        int a = prime[i];
        for(int j = a+a; j<mx; j+=a){
            pdiv[j].push_back(a);
        }
    }
}
void bfs(int s, int t)
{
    memset(level, -1, sizeof level);
    level[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        int sz = pdiv[x].size();
        for(int i=0; i<sz; i++){
            int d = pdiv[x][i];
            int num = x+d;

            if(level[num]==-1 && num<=t){
                //cout<<"num = "<<num<<endl;
                level[num] = level[x]+1;
                Q.push(num);
            }
            if(num==t) return;
        }
    }
}

int main()
{

    getPdiv();
//    for(int i=0; i<=20; i++){
//        int sz =pdiv[i].size();
//        cout<<i<<" has "<<sz<<": ";
//        for(int j=0; j<sz; j++)
//            cout<<pdiv[i][j]<<" ";
//        printf("\n");
//    }
    //freopen("out.txt","w",stdout);
    int tc,s,t;
    scanf("%d",&tc);

    for(int cs = 1; cs<=tc;cs++){
        scanf("%d%d",&s,&t);
        bfs(s,t);
        printf("Case %d: %d\n",cs, level[t]);
    }
    return 0;
}
