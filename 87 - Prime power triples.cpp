
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
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

const int N=7071;
const int MX=50000000;

bool p[N+1];
vector<int> primes;

void euler() {
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes.pb(i);
        }
        for (int j=0;j<primes.size()&&i*primes[j]<=N;j++) {
            p[i*primes[j]]=1;
            if (i%primes[j]==0) break;
        }
    }
}

int p2(int x) { return x*x; }
int p3(int x) { return x*x*x; }
int p4(int x) { return x*x*x*x; }

int main()
{
    euler();
    int cnt=primes.size();
    unordered_set<int> s;
    for (int i=0;i<cnt&&p4(primes[i])<MX;i++) {
        int a=p4(primes[i]);
        for (int j=0;j<cnt&&a+p3(primes[j])<MX;j++) {
            int b=a+p3(primes[j]);
            for (int k=0;k<cnt&&b+p2(primes[k])<MX;k++) {
                s.insert(b+p2(primes[k]));
            }
        }
    }
    printf("%d\n",(int)s.size());
}