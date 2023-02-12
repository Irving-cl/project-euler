
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

const int N=10;

ll p10[10];
bool vis[10],ok[10];
vector<ll> vec[10];
vector<int> idx;
int d;

void init() {
    p10[0]=1;
    for (int i=1;i<10;i++) p10[i]=p10[i-1]*10;
}

bool is_prime(ll x) {
    if (x%2==0) return false;
    for (ll i=3;i*i<=x;i+=2) {
        if (x%i==0) return false;
    }
    return true;
}

void dfs1(int x,int digit,ll fix,ll add) {
    if (x==d) {
        if (is_prime(fix+add)) {
            vec[digit].pb(fix+add);
        }
    } else {
        for (int i=0;i<10;i++) {
            if (idx[x]==0&&i==0) continue;
            if (i!=digit) {
                dfs1(x+1,digit,fix,add+p10[N-1-idx[x]]*i);
            }
        }
    }
}

void work() {
    ll fix=0;
    idx.clear();
    for (int i=0;i<10;i++) {
        if (vis[i]) {
            fix+=p10[N-1-i];
        } else {
            idx.pb(i);
        }
    }
    for (int i=0;i<10;i++) {
        if (ok[i]) continue;
        if (i==0&&vis[0]) continue;
        dfs1(0,i,fix*(ll)i,0);
    }
}

void dfs(int idx,int n) {
    if (n==0) {
        work();
        return;
    }
    for (int i=idx;i<N&&n<=N-i;i++) {
        vis[i]=true;
        dfs(i+1,n-1);
        vis[i]=false;
    }
}

int main()
{
    init();
    int cnt=0;
    int dd=N-1;
    while (cnt<10) {
        d=N-dd;
        dfs(0,dd);
        for (int i=0;i<10;i++) {
            if (!ok[i]&&!vec[i].empty()) {
                cnt++;
                ok[i]=true;
            }
        }
        dd--;
    }
    ll sum=0;
    for (int i=0;i<10;i++) {
        printf("i:%d ",i);
        for (ll ele:vec[i]) {
            printf("%lld ",ele);
            sum+=ele;
        }
        printf("\n");
    }
    printf("ans:%lld\n",sum);
}
