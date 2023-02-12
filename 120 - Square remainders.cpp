
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

bool vis[1001];

int mx_rem(int a) {
    memset(vis,0,sizeof(vis));
    int num=-2;
    int mx=0;
    while (true) {
        num=(num+4)%a;
        if (vis[num]) break;
        mx=max(mx,num);
        vis[num]=1;
    }
    return mx;
}

int main() {
    ll ans=0;
    for (int i=3;i<=1000;i++) {
        ans+=(ll)i*mx_rem(i);
    }
    printf("%lld\n",ans);
}
