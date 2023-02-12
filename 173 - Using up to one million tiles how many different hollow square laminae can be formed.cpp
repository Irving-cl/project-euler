
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

const int N=1000000;

int main()
{
    ll ans=0;
    for (int v=2;v*v<N;v+=2) {
        int hi=N/v;
        ans+=(ll)(hi-v)/2;
    }
    printf("%lld\n",ans);
}
