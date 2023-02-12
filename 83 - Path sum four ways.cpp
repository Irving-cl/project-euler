
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
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

int grid[100][100];
int dp[100][100];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

struct node {
    int x,y,val;
    node(int p1,int p2,int p3):x(p1),y(p2),val(p3){};
    bool operator<(const node& rhs) const {
        return val>rhs.val;
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    for (int i=0;i<80;i++) {
        for (int j=0;j<80;j++) {
            scanf("%d",&grid[i][j]);
        }
    }

    memset(dp,INF,sizeof(dp));
    priority_queue<node> pq;
    dp[0][0]=grid[0][0];
    pq.push(node(0,0,dp[0][0]));
    while (!pq.empty()) {
        node cur=pq.top();
        pq.pop();
        for (int i=0;i<4;i++) {
            int x=cur.x+dir[i][0];
            int y=cur.y+dir[i][1];
            if (x>=0&&x<80&&y>=0&&y<80) {
                int val=cur.val+grid[x][y];
                if (val<dp[x][y]) {
                    dp[x][y]=val;
                    pq.push(node(x,y,val));
                }
            }
        }
    }
    printf("%d\n",dp[79][79]);
}
