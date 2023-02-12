
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <unordered_set>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int N=51;
bool p[N+1];
int primes[N],tot=0;
ll row[2][N+2];
unordered_set<ll> us;

void init() {
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes[tot++]=i;
        }
        for (int j=0;j<tot&&i*primes[j]<=N;j++) {
            p[i*primes[j]]=true;
            if (i%primes[j]==0) break;
        }
    }
}

bool sf(ll x) {
    for (int i=0;i<tot&&primes[i]*primes[i]<=x;i++) {
        if (x%(primes[i]*primes[i])==0) return false;
    }
    return true;
}

int main()
{
    init();
    ll ans=0;
    int rIdx=0;
    row[rIdx][1]=1;
    for (int i=1;i<=N;i++,rIdx=1-rIdx) {
        for (int j=1;j<=i;j++) {
            if (sf(row[rIdx][j])) us.insert(row[rIdx][j]);
        }
        row[1-rIdx][1]=row[1-rIdx][i+1]=1;
        for (int j=2;j<i+1;j++) {
            row[1-rIdx][j]=row[rIdx][j-1]+row[rIdx][j];
        }
    }
    for (ll ele:us) ans+=ele;
    printf("%lld\n",ans);
}
