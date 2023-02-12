
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

const int N=90;
bool p[N+1];
ll primes[N+1];
int tot=0;
int pos[30];
vector<ll> vec;
vector<ll> foo;

void init() {
    for (ll i=2;i<=N;i++) {
        if (!p[i]) {
            primes[++tot]=i;
        }
        for (int j=1;j<=tot&&i*primes[j]<=N;j++) {
            p[i*primes[j]]=true;
            if (i%primes[j]==0) {
                break;
            }
        }
    }
}

int main() {
    init();
    db cmp=15499.0/94744.0;
    printf("cmp:%.3f\n",cmp);
    vec.pb(1);
    foo.pb(1);
    while (true) {
        ll mn=1ll<<62;
        ll mnfoo=-1;
        for (int i=1;i<=tot;i++) {
            ll tmp=primes[i]*vec[pos[i]];
            if (tmp<mn) {
                mn=tmp;
                mnfoo=foo[pos[i]]*(vec[pos[i]]%primes[i]==0?primes[i]:primes[i]-1);
            }
        }
        db ratio=(db)mnfoo/(db)(mn-1);
        if (ratio<cmp) {
            printf("ratio:%.3f d:%lld\n",ratio,mn);
            break;
        }
        vec.pb(mn);
        foo.pb(mnfoo);
        for (int i=1;i<=tot;i++) {
            ll tmp=primes[i]*vec[pos[i]];
            if (tmp==mn) {
                pos[i]++;
            }
        }
    }
}

