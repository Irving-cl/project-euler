
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

const int N=10000000;
bool p[N+10];
int primes[N],tot=0;
int a[N+10];

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

int dv(int x) {
    if (!p[x]) return 2;
    int ret=1;
    for (int i=0;i<tot&&primes[i]<=x;i++) {
        if (x%primes[i]==0) {
            int cnt=0;
            while (x%primes[i]==0) {
                cnt++;
                x/=primes[i];
            }
            ret*=(cnt+1);
            if (!p[x]) {
                ret*=2;
                break;
            }
        }
    }
    return ret;
}

int main()
{
    get_primes();
    int ans=0;
    int a=dv(1);
    for (int i=2;i<=N;i++) {
        int b=dv(i);
        if (a==b) ans++;
        a=b;
    }
    printf("ans:%d\n",ans);
}
