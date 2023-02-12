
#include <stdio.h>
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

db dp1[10][37],dp2[7][37];
db pfs[37];

int main()
{
    dp1[0][0]=1.0;
    for (int i=1;i<=9;i++) {
        for (int j=i;j<=i*4;j++) {
            for (int k=1;k<=min(4,j);k++) {
                dp1[i][j]+=dp1[i-1][j-k]*0.25;
            }
        }
    }
    dp2[0][0]=1.0;
    for (int i=1;i<=6;i++) {
        for (int j=i;j<=i*6;j++) {
            for (int k=1;k<=min(6,j);k++) {
                dp2[i][j]+=dp2[i-1][j-k]/6.0;
            }
        }
    }
    for (int i=1;i<=36;i++) pfs[i]=pfs[i-1]+dp2[6][i];
    db ans=0.0;
    for (int i=1;i<=36;i++) ans+=dp1[9][i]*pfs[i-1];
    printf("%.7f\n",ans);
}