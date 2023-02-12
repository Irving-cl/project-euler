
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

int dp[2][100];
int grid[100][100];
const int N=80;

int main()
{
    freopen("input.txt","r",stdin);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            scanf("%d",&grid[i][j]);
        }
    }
    int rIdx=0;
    int ans=INF;
    for (int i=1;i<=N;i++,rIdx=1-rIdx) {
        memset(dp[rIdx],INF,sizeof(dp[rIdx]));
        for (int j=1;j<=N;j++) {
            if (dp[rIdx][j]>=dp[1-rIdx][j]+grid[j][i]) {
                dp[rIdx][j]=dp[1-rIdx][j]+grid[j][i];
                int accum=dp[rIdx][j];
                for (int k=j-1;k>0;k--) {
                    accum+=grid[k][i];
                    dp[rIdx][k]=min(dp[rIdx][k],accum);
                }
                accum=dp[rIdx][j];
                for (int k=j+1;k<=N;k++) {
                    accum+=grid[k][i];
                    dp[rIdx][k]=min(dp[rIdx][k],accum);
                }
            }
        }
    }
    for (int i=1;i<=N;i++) {
        ans=min(ans,dp[1-rIdx][i]);
    }
    printf("%d\n",ans);
}