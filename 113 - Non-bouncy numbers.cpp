
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

const int N=100;
ll dp[2][10];

int main()
{
    ll ans=18;

    int rIdx=0;
    for (int i=0;i<10;i++) dp[rIdx][i]=1;
    rIdx=1-rIdx;
    for (int i=1;i<N;i++) {
        memset(dp[rIdx],0,sizeof(dp[rIdx]));
        for (int j=0;j<10;j++) {
            for (int k=0;k<=j;k++) {
                dp[rIdx][j]+=dp[1-rIdx][k];
            }
            if (j>0) ans+=dp[rIdx][j];
        }
        rIdx=1-rIdx;
    }

    memset(dp,0,sizeof(dp));
    rIdx=0;
    for (int i=0;i<10;i++) dp[rIdx][i]=1;
    rIdx=1-rIdx;
    for (int i=1;i<N;i++) {
        memset(dp[rIdx],0,sizeof(dp[rIdx]));
        for (int j=1;j<10;j++) {
            for (int k=j;k<10;k++) {
                dp[rIdx][j]+=dp[1-rIdx][k];
            }
            ans+=dp[rIdx][j];
        }
        rIdx=1-rIdx;
    }

    ans-=N*9;
    printf("ans:%lld\n",ans);
}
