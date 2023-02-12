
#include <stdio.h>
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

const int N=100000;

bool p[N+10];
int primes[N+10];
int tot=0;

int rad(int x) {
    int ret=1;
    if (!p[x]) return x;
    for (int i=1;i<=tot;i++) {
        if (x%primes[i]==0) ret*=primes[i];
        while (x%primes[i]==0) x/=primes[i];
        if (!p[x]) return ret*x;
    }
    return ret;
}

int main()
{
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes[++tot]=i;
        }
        for (int j=1;j<=tot&&i*primes[j]<=N;j++) {
            p[i*primes[j]]=1;
            if (i%primes[j]==0) break;
        }
    }
    vector<PII> vec;
    for (int i=1;i<=N;i++) {
        vec.pb(mp(rad(i),i));
    }
    sort(vec.begin(),vec.end());
    printf("%d %d\n",vec[9999].first,vec[9999].second);
}