
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

const int N=1000000;
bool p[N+10];
int primes[N+10];
int tot=0;
unordered_set<int> us;

void init() {
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes[tot++]=i;
            us.insert(i);
        }
        for (int j=0;j<tot&&i*primes[j]<=N;j++) {
            p[i*primes[j]]=true;
            if (i%primes[j]==0) break;
        }
    }
}

ll cal(ll x,ll y) {
    return x*x*x-y*y*y;
}

int main()
{
    int ans=0;
    init();
    for (int i=1;i<=600;i++) {
        for (int j=i+1;cal(j,i)<=N;j++) {
            if (us.find((int)cal(j,i))!=us.end()) ans++;
        }
    }
    printf("ans:%d\n",ans);
}