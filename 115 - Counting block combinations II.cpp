
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int M=50;
ll dp[2][M+1];

int main()
{
    int rIdx=0;
    dp[rIdx][0]=1;
    for (int i=1;;i++,rIdx=1-rIdx) {
        memset(dp[1-rIdx],0,sizeof(dp[1-rIdx]));
        dp[1-rIdx][0]+=dp[rIdx][0]+dp[rIdx][M];
        for (int j=1;j<M;j++) {
            dp[1-rIdx][j]+=dp[rIdx][j-1];
        }
        dp[1-rIdx][M]+=dp[rIdx][M-1]+dp[rIdx][M];
        int tmp=dp[1-rIdx][0]+dp[1-rIdx][M];
        if (tmp>1000000) {
            printf("ans:%d %d\n",i,tmp);
            break;
        }
    }
}
