
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

const int N=50;
ll dp[N+1][4];

int main()
{
    dp[0][0]=1;
    for (int i=1;i<=N;i++) {
        dp[i][0]+=dp[i-1][0]+dp[i-1][3];
        dp[i][1]+=dp[i-1][0];
        dp[i][2]+=dp[i-1][1];
        dp[i][3]+=dp[i-1][2]+dp[i-1][3];
    }
    printf("%lld\n",dp[N][0]+dp[N][3]);
}
