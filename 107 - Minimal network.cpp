
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
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

const int N=40;

int dis[N+5][N+5];
bool vis[N+5];
struct node {
    int id,val;
    bool operator<(const node& rhs) const {
        return val>rhs.val;
    }
};

int main() {
    int sum=0;
    freopen("input.txt","r",stdin);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            scanf("%d",&dis[i][j]);
            if (j>i) sum+=dis[i][j];
        }
    }
    priority_queue<node> pq;
    pq.push({1,0});
    int cnt=0;
    int ans=0;
    while (cnt<N) {
        node cur=pq.top();
        pq.pop();
        if (vis[cur.id]) continue;
        vis[cur.id]=1;
        cnt++;
        ans+=cur.val;
        for (int i=1;i<=N;i++) {
            if (!vis[i]&&dis[cur.id][i]>0) {
                pq.push({i,dis[cur.id][i]});
            }
        }
    }
    printf("sum:%d ans:%d\n",sum,sum-ans);
}

