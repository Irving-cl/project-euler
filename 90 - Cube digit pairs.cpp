
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

int a[6];
vector<vector<int>> comp;

void dfs(int idx,int cur) {
    if (idx==6) {
        comp.pb(vector<int>(a,a+6));
    } else {
        for (int i=cur;10-i>5-idx;i++) {
            a[idx]=i;
            dfs(idx+1,i+1);
        }
    }
}

int sqrs[9][2];

bool contains(vector<int>& vec,int ele) {
    for (int i:vec) if (i==ele) return true;
    if (ele==6) {
        for (int i:vec) if (i==9) return true;
    }
    if (ele==9) {
        for (int i:vec) if (i==6) return true;
    }
    return false;
}

bool check(int i,int j,int k) {
    return (contains(comp[i],sqrs[k][1])
          &&contains(comp[j],sqrs[k][0])) ||
           (contains(comp[i],sqrs[k][0])
          &&contains(comp[j],sqrs[k][1]));
}

int main()
{
    dfs(0,0);
    for (int i=1;i<10;i++) {
        int x=i*i;
        sqrs[i-1][0]=x/10;
        sqrs[i-1][1]=x%10;
    }
    int ans=0;
    for (int i=0;i<comp.size();i++) {
        for (int j=i;j<comp.size();j++) {
            bool flag=true;
            for (int k=0;k<9;k++) {
                if (!check(i,j,k)) {
                    flag=false;
                    break;
                }
            }
            if (flag) ans++;
        }
    }
    printf("%d\n",ans);
}
