
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

int gcd(int a,int b) {
    return b==0?a:gcd(b,a%b);
}

int main() {
    ll ans=0;
    for (int m=2;m<=25819;m++) {
        for (int n=m-1;n>0;n-=2) {
            if (gcd(m,n)==1) {
                ll a=(ll)m*m-3LL*n*n;
                ll b=(ll)m*m-4LL*m*n+(ll)n*n;
                ll tmp=m*m+n*n;
                if (3*tmp-1>1000000000) break;
                if (a==1) {
                    ans+=3LL*tmp+1;
                } else if (a==-1) {
                    ans+=3LL*tmp-1;
                }
                if (b==-1) {
                    ans+=3LL*tmp+1;
                } else if (b==1) {
                    ans+=3LL*tmp-1;
                }
            }
        }
    }
    printf("%lld\n",ans);
}

