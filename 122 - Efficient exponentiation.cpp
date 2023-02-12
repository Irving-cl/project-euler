
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int N=200;

int m[N+10];
vector<int> vec;

void dfs(int idx) {
    if (idx==12) return;
    int last=vec.back();
    for (int ele:vec) {
        int tmp=ele+last;
        if (tmp>N) continue;
        m[tmp]=min(m[tmp],idx);
        vec.pb(tmp);
        dfs(idx+1);
        vec.pop_back();
    }
}

int main()
{
    memset(m,INF,sizeof(m));
    m[1]=0;
    vec.pb(1);
    dfs(1);
    int sum=0;
    for (int i=1;i<=N;i++) {
        sum+=m[i];
    }
    printf("ans:%d\n",sum);
}
