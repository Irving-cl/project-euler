
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
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

const int N=10000;

ll sqr[N+10];
int digits[12];
vector<int> pld;

int get_num(int d) {
    int ret=0;
    for (int i=0;i<d;i++) {
        ret=ret*10+digits[i];
    }
    return ret;
}

void dfs(int idx,int d) {
    if (idx<0) {
        pld.pb(get_num(d));
        return;
    }
    for (int i=0;i<10;i++) {
        if (i==0&&idx==0) continue;
        digits[idx]=digits[d-1-idx]=i;
        dfs(idx-1,d);
    }
}

void gen_pld(int d) {
    if (d&1) {
        for (int i=0;i<10;i++) {
            digits[d/2]=i;
            dfs(d/2-1,d);
        }
    } else {
        dfs(d/2-1,d);
    }
}

bool check(ll x) {
    int i=1,j=2;
    ll sum=sqr[i]+sqr[j];
    while (i<j) {
        if (sum==x) return true;
        else if (sum<x) {
            sum+=sqr[++j];
        } else {
            sum-=sqr[i++];
        }
    }
    return false;
}

int main()
{
    for (int i=1;i<=N;i++) {
        sqr[i]=i*i;
    }
    for (int i=1;i<=8;i++) {
        gen_pld(i);
    }
    ll ans=0;
    for (int i:pld) {
        if (check(i)) ans+=i;
    }
    printf("%lld\n",ans);
}
