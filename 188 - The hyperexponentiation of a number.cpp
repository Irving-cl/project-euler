
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

using namespace std;

const ll mod=1e8;

ll qp(ll x,ll y) {
    ll res=1;
    while (y>0) {
        if (y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y=y>>1;
    }
    return res;
}

int main()
{
    ll a=1777;
    int b=1855;
    ll res=1;
    for (int i=0;i<b;i++) {
        res=qp(a,res);
    }
    printf("%lld\n",res);
}