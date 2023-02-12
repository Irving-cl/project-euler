
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

ll dp[60];
const int N=50;

ll work(int x) {
    memset(dp,0,sizeof(dp));
    for (int i=x;i<=N;i++) {
        dp[i]=dp[i-1]+dp[i-x]+1;
    }
    return dp[N];
}

int main()
{
    ll ans=0;
    for (int i=2;i<=4;i++) { ans+=work(i); }
    printf("%lld\n",ans);
}
