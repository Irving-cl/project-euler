
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int N=15;

db dp[N+1][N+1];

int main() {
    for (int i=0;i<=N;i++) {
        for (int j=0;j<=N;j++) {
            dp[i][j]=0.0;
        }
    }
    dp[0][0]=1.0;
    for (int i=1;i<=N;i++) {
        dp[i][0]=dp[i-1][0]*i/(i+1);
        for (int j=1;j<=i;j++) {
            dp[i][j]=dp[i-1][j]*i/(i+1)+dp[i-1][j-1]/(i+1);
        }
    }
    db p=0.0;
    for (int i=N;i*2>N;i--) p+=dp[N][i];
    printf("%.3f\n",(1.0-p)/p);
}

