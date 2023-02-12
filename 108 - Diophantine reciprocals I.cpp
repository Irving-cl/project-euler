
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

const int N=200000;
int tot=0;
bool p[N+10];
int primes[N+10];

int div(int x) {
    int ret=1;
    if (!p[x]) return ret;
    for (int i=0;i<tot&&primes[i]<=x;i++) {
        if (x%primes[i]==0) {
            int tmp=0;
            while (x%primes[i]==0) {
                tmp++;
                x/=primes[i];
            }
            ret*=(2*tmp+1);
        }
        if (!p[x]) {
            return ret*3;
        }
    }
    return ret;
}

int main() {
    p[1]=1;
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes[tot++]=i;
        }
        for (int j=0;j<tot&&i*primes[j]<=N;j++) {
            p[i*primes[j]]=1;
            if (i%primes[j]==0) break; 
        }
    }
    for (int i=2;i<=N;i++) {
        if (div(i)>2000) {
            printf("ans:%d\n",i);
            break;
        }
    }
}
