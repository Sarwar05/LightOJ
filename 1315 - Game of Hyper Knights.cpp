#include<bits/stdc++.h>
using namespace std;
#define mx 752
int grid[mx][mx];
int dirx[] = {-2, -3, -2, -1, -1, +1};
int diry[] = {+1, -1, -1, -2, -3, -2};
int getGrundy(int x, int y)
{
    //cout<<"in "<<x<< " "<<y<<endl;
    //if(x<0 || y<0) return 0;
    if(grid[x][y]!=-1) return grid[x][y];
    set<int> st;
    for(int i=0; i<6; i++){
        int xx = dirx[i] + x;
        int yy = y + diry[i];
        if(xx>=0 && yy>=0)
            st.insert(getGrundy(xx,yy));
    }
    int val=0;
    set<int>::iterator it = st.begin();
    while(it!=st.end()){
        if((*it)!=val) return grid[x][y] = val;
        it++;
        val++;
    }
    return grid[x][y] = val;
}
void process()
{
    memset(grid,-1,sizeof grid);
    for(int i=0; i<mx; i++){
        for(int j=0; j<mx; j++){
            grid[i][j] = getGrundy(i,j);
        }
    }
}
int main()
{
    int tc,cs=1,n,x,y;
    process();
    scanf("%d",&tc);
    while(tc--){
        int xxx=0;
        scanf("%d",&n);
        while(n--){
            scanf("%d%d",&x,&y);
            xxx^=grid[x][y];
        }
        printf("Case %d: %s\n",cs++,(xxx)?"Alice":"Bob");
    }
    return 0;
}
