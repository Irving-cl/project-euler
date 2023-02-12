
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

ll p[15];
ll c(int n,int m) {
    return p[n]/p[m]/p[n-m];
}

void init() {
    p[0]=1;
    for (int i=1;i<13;i++) p[i]=p[i-1]*i;
}

vector<int> cur;
bool check(int n) {
    bool vis[15]={0};
    for (int i:cur) vis[i]=true;
    vector<int> other;
    for (int i=1;i<=n;i++) if (!vis[i]) other.pb(i);
    vector<int> x;
    for (int i=0;i<cur.size();i++) x.pb(cur[i]<other[i]);
    for (int i=1;i<x.size();i++) {
        if (x[i]!=x[0]) return true;
    }
    return false;
}

void dfs(int idx,int rem,int n,int& tmp) {
    if (rem==0) {
        if (check(n)) tmp++; 
        return;
    }
    for (int i=idx;i+rem-1<=n;i++) {
        cur.pb(i);
        dfs(i+1,rem-1,n,tmp);
        cur.pop_back();
    }
}

int main()
{
    init();
    ll ans=0;
    for (int i=4;i<=12;i+=2) {
        int tmp=0;
        dfs(1,i/2,i,tmp);
        ans+=tmp*c(12,i);
    }
    printf("%lld\n",ans/2);
}
