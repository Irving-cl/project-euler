
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int N=12000;
int n[N+5];

bool dfs(int cnt,int pro,int sum,int start) {
    int k=cnt+pro-sum;
    if (k<=N) {
        if (pro<n[k]) n[k]=pro;
        for (int i=start;pro*i<=N*2;i++) {
            dfs(cnt+1,pro*i,sum+i,i);
        }
    }
}

int main()
{
    memset(n,INF,sizeof(n));
    dfs(1,1,1,2);
    int ans=0;
    set<int> s;
    for (int i=2;i<=N;i++) {
        s.insert(n[i]);
    }
    for (int ele:s) ans+=ele;
    printf("%d\n",ans);
}
