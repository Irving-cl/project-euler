
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <unordered_set>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int N=30;
ll dp[N][3][2];

int main()
{
    dp[0][0][0]=1;
    for (int i=1;i<=N;i++) {
        dp[i][0][0]=dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0];
        dp[i][1][0]=dp[i-1][0][0];
        dp[i][2][0]=dp[i-1][1][0];
        dp[i][0][1]=dp[i][0][0]+dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1];
        dp[i][1][1]=dp[i-1][0][1];
        dp[i][2][1]=dp[i-1][1][1];
    }
    ll ans=0;
    for (int i=0;i<3;i++) {
        for (int j=0;j<2;j++) {
            ans+=dp[N][i][j];
        }
    }
    printf("%lld\n",ans);
}