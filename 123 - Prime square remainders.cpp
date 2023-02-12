
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int N=500010;

bool p[N];
int primes[N],tot=0;

void get_primes() {
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes[tot++]=i;
        }
        for (int j=0;j<tot&&i*primes[j]<N;j++) {
             p[i*primes[j]]=true;
             if (i%primes[j]==0) break;
        }
    }
    printf("tot:%d\n",tot);
}

int main() {
    get_primes();
    for (int i=0;i<tot;i++) {
        if (i%2==0) {
            ll tmp=2LL*(i+1)*primes[i];
            ll sqr=(ll)primes[i]*primes[i];
            if (tmp%sqr>10000000000LL) {
                printf("ans:%d\n",i+1);
                break;
            }
        }
    }
}

