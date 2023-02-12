
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

const int N=100000;
const int M=1000000;
ll p[1000];
ll dp[N+1];

int main() {
    for (int i=1,j=0;j<1000;j++) {
        p[j]=i*(3*i-1)/2;
        i*=-1;
        if (j%2==1) i++;
    }
    dp[0]=1;
    dp[1]=1;
    for (int i=2;i<N;i++) {
        for (int j=0;p[j]<=i;j++) {
            if ((j%4)>1) {
                dp[i]-=dp[i-p[j]];
                if (dp[i]<0) dp[i]+=M;
            } else {
                dp[i]+=dp[i-p[j]];
            }
            dp[i]=dp[i]%M;
        }
        if (dp[i]==0) {
            printf("ans: %d\n",i);
            break;
        }
    }
}
