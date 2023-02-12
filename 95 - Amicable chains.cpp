
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const int MXN=1000000;

int a[MXN+10];
vector<int> rg[MXN+10];
bool vis[MXN+10];
int mx=1,ans;
stack<int> st;
vector<int> dfstree;

int div_sum(int x) {
    int ret=0;
    for (int i=1;i*i<=x;i++) {
        if (x%i==0) {
            ret+=i;
            if (i*i<x&&i>1) ret+=x/i;
        }
    }
    return ret;
}

void dfs1(int u) {
    if (vis[u]) return;
    vis[u]=true;
    if (a[u]>0) {
        dfs1(a[u]);
    }
    st.push(u);
}

void dfs2(int u) {
    if (vis[u]) return;
    vis[u]=true;
    dfstree.pb(u);
    for (int v:rg[u]) {
        dfs2(v);
    }
}

void kosaraju() {
    memset(vis,0,sizeof(vis));
    for (int i=2;i<=MXN;i++) {
        dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    while (!st.empty()) {
        dfstree.clear();
        int u=st.top();
        st.pop();
        dfs2(u);
        if (dfstree.size()>mx) {
            int tmp=INF;
            for (int v:dfstree) tmp=min(tmp,v);
            ans=tmp;
            mx=dfstree.size();
        }
    }
}

int main() {
    for (int i=2;i<=MXN;i++) {
        a[i]=div_sum(i);
        if (a[i]<2||a[i]>MXN) a[i]=-1;
        else rg[a[i]].pb(i);
    }
    kosaraju();
    printf("%d\n",ans);
    printf("longest:%d\n",mx);
}
