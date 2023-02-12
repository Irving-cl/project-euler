
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
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

const int N=1001000;

ll x1,x2;
void ex_gcd(ll a,ll b,ll c) {
    if (b==1) {
        x2=0;
        x1=c;
    } else {
        ex_gcd(b,a%b,c%b);
        ll tmp=x1;
        x1=x2-(a/b)*x1+(c/b);
        x2=tmp;
    }
}

bool p[N+10];
ll primes[N+10];
int tot=0;

void init() {
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes[tot++]=i;
        }
        for (int j=0;j<tot&&i*primes[j]<=N;j++) {
            p[i*primes[j]]=1;
            if (i%primes[j]==0) break;
        }
    }
}

ll p10(int x) {
    ll num=10;
    while (num<x) {
        num*=10;
    }
    return num;
}

int main() {
    ll ans=0;
    init();
    for (int i=2;primes[i]<=1000000;i++) {
        ex_gcd(p10(primes[i]),primes[i+1],-primes[i]);
        if (x2>0) {
            x2%=primes[i+1];
        } else {
            ll k=abs(x2)/primes[i+1]+1;
            x2+=k*primes[i+1];
        }
        ll s=p10(primes[i])*x2+primes[i];
        ans+=s;
    }
    printf("ans:%lld\n",ans);
}
