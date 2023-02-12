
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int MXN=1000000;

bool p[MXN+10];
vector<int> primes;
int phi[MXN+10];

int main() {
    p[1]=1;
    for (int i=2;i<=MXN;i++) {
        if (!p[i]) {
            primes.pb(i);
            phi[i]=i-1;
        }
        for (int j=0;j<primes.size()&&i*primes[j]<=MXN;j++) {
            p[i*primes[j]]=1;
            if (i%primes[j]==0) {
                int x=i;
                int y=primes[j];
                int tmp=y;
                while (x%y==0) {
                    x/=y;
                    tmp*=y;
                }
                if (x==1) {
                    phi[tmp]=tmp*(y-1)/y;
                } else {
                    phi[x*tmp]=phi[x]*phi[tmp];
                }
                break;
            }
            phi[i*primes[j]]=phi[i]*phi[primes[j]];
        }
    }
    
    ll ans=0;
    for (int i=2;i<=MXN;i++) {
        ans+=phi[i];
    }
    printf("%lld\n",ans);
}