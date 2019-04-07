#include<stdio.h>
#include<string.h>
#define ll long long
/**
consider a board (N-1)x(N-1) in which we put K rooks
what if consider NxN board to put K rooks

    o o o x
    o o o x
    o o o x
    x x x x

we can add 0, 1, or 2 rooks in our newly added cells in general cases
*/
ll dp[32][32] = {0};
ll solve(int size, int rook)
{
    if(rook==0) return 1LL;
    if(size<=0 || rook>size || rook<0) return 0LL;
    ll ret = dp[size][rook];
    if(ret!=-1) return ret;
    ret = 0;
    /// current size of board is NxN
    /**
    put 0 rook:
    Just put the newly added cells blank
    so result = result for (N-1)x(N-1) with K rooks
    */
    ret+=solve(size-1,rook);
    /**
    put 1 rook:
    we can put 1 rook in free row/column of (N-1)x(N-1) with (K-1) rooks
    first count number of free row & column of board
    (N-1)x(N-1) with (K-1) rooks
    and we have an additional cell (N,N) to put one rook

    */
    ll free = (size-1) - (rook-1);
    free*=2;
    free++;
    ret+= (free*solve(size-1, rook-1));
    /**
    put 2 rooks:
    we can put 2 rooks in free row/column of (N-1)x(N-1) with (K-2) rooks
    first count number of free row & column of board
    (N-1)x(N-1) with (K-2) rooks
    NOTE that we can't put in (N,N) cell, because it will it will block
    our way to put another rook
    */
    free = (size-1) - (rook-2);
    free*=free;
    ret+= (free*solve(size-1, rook-2));

    return dp[size][rook] = ret;
}
int main()
{
    memset(dp, -1, sizeof dp);
    int tc, cs=1,n,k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n, &k);
        printf("Case %d: %lld\n", cs++, (k>n) ? 0LL : solve(n,k));
    }
}
