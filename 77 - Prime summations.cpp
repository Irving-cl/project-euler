
#include <stdio.h>
#include <iostream>
#include <algorithm>
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

int p[10010];
int dp[10010][1001];
vector<int> vec;

int main()
{
    for (int i=2;i<=10000;i++) {
        if (!p[i]) {
            vec.pb(i);
        }
        for (int j=0;j<vec.size()&&i*vec[j]<=10000;j++) {
            p[i*vec[j]]=1;
            if (i%vec[j]==0) break;
        }
    }
    for (int i=1;i<=1000;i++) dp[0][i]=1;
    for (int i=1;i<=10000;i++) {
        for (int j=0;j<1000;j++) {
            if (vec[j]<=i) dp[i][j+1]=dp[i][j]+dp[i-vec[j]][j+1];
            else dp[i][j+1]=dp[i][j];
        }
        if (dp[i][1000]>5000) {
            printf("%d %d\n",i,dp[i][1000]);
            break;
        }
    }
    
}