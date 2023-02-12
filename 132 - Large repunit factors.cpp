
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

using namespace std;

const int N=200000;
bool p[N+10];
ll primes[N+10];
int tot=0;
ll p10[10];

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
    p10[0]=1;
    for (int i=1;i<10;i++) p10[i]=p10[i-1]*10;
}

ll qp(ll num,ll p,ll mod) {
    ll ret=1;
    ll tmp=num;
    while (p) {
        if (p&1) ret=(ret*tmp)%mod;
        tmp=(tmp*tmp)%mod;
        p=p>>1;
    }
    return ret;
}

bool check(int i,ll prime) {
    ll rem=0;
    for (int j=0;j<=9;j++) {
        rem=(rem+qp(10,p10[i]*j,prime))%prime;
    }
    return rem==0;
}

int main()
{
    init();
    map<ll,int> m;
    for (int i=0;i<9;i++) {
        for (int j=0;j<tot;j++) {
            if (check(i,primes[j])) m[primes[j]]++;
        }
    }
    printf("%d\n",(int)m.size());
    for (auto& entry:m) printf("%lld %d\n",entry.first,entry.second);
    ll sum=0;
    int i=0;
    for (auto& entry:m) {
        if (i<40) {
            i++;
            sum+=entry.first;
        }
    }
    printf("%lld\n",sum);
}
