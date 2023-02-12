
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

bool num[10000];
int p[4];

const db eps=1e-8;

int is_integer(db x) {
    if (x - (db)((int)x) > eps) return -1;
    else return (int)x;
}

void dfs_op(int idx,db val) {
    if (idx==0) {
        int tmp=is_integer(val);
        if (tmp>0) num[tmp]=true;
        return;
    }
    dfs_op(idx-1,(db)p[idx-1]+val);
    dfs_op(idx-1,(db)p[idx-1]-val);
    dfs_op(idx-1,val-(db)p[idx-1]);
    dfs_op(idx-1,(db)p[idx-1]*val);
    if (val>eps) dfs_op(idx-1,(db)p[idx-1]/val);
    dfs_op(idx-1,val/(db)p[idx-1]);
}

void dfs(int idx) {
    if (idx==4) {
        dfs_op(3,p[3]);
        return;
    }
    for (int i=idx;i<4;i++) {
        swap(p[idx],p[i]);
        dfs(idx+1);
        swap(p[idx],p[i]);
    }
}

int work(int a,int b,int c,int d) {
    p[0]=a;p[1]=b;p[2]=c;p[3]=d;
    memset(num,0,sizeof(num));
    dfs(0);
    int cnt=1;
    while (num[cnt]) cnt++;
    return cnt;
}

int main()
{
    int ans=0;
    for (int a=1;a<=9;a++) {
        for (int b=a+1;b<=9;b++) {
            for (int c=b+1;c<=9;c++) {
                for (int d=c+1;d<=9;d++) {
                    int tmp=work(a,b,c,d);
                    if (tmp>ans) {
                        printf("%d %d %d %d\n",a,b,c,d);
                        ans=tmp;
                    }
                }
            }
        }
    }
}
