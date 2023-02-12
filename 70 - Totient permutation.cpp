
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

const int MXN=10000000;

bool p[MXN+10];
vector<int> primes;
int phi[MXN+10];
int cnt1[10],cnt2[10];

bool foo(int x,int y) {
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    while (x) {
        cnt1[x%10]++;
        x/=10;
    }
    while (y) {
        cnt2[y%10]++;
        y/=10;
    }
    for (int i=0;i<10;i++) {
        if (cnt1[i]!=cnt2[i]) return false;
    }
    return true;
}

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
    
    db ratio=2.0;
    int cand=-1;
    for (int i=2;i<=MXN;i++) {
        if (foo(i,phi[i])) {
            if ((db)i/(db)phi[i]<ratio) {
                cand=i;
                ratio=(db)i/(db)phi[i];
            }
        }
    }
    printf("phi(%d):%d\n", cand, phi[cand]);
}