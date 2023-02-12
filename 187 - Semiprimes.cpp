
#include <stdio.h>
#include <stdlib.h>
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

const int N=50000000;
bool p[N+10];
ll primes[N];
int tot=0;

void get_primes() {
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
}

int main()
{
    get_primes();
    primes[tot++]=100000000000LL;
    ll ans=0;
    for (int i=0;primes[i]*primes[i]<100000000;i++) {
        int cnt=upper_bound(primes,primes+tot,100000000/primes[i])-(primes+i);
        ans+=cnt;
    }
    printf("ans:%lld\n",ans);
}
