
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

struct node {
    int mul;
    int val;
} dt[100];

int tot=0;

void init() {
    for (int i=1;i<=20;i++) {
        for (int j=1;j<=3;j++) {
            dt[tot].mul=j;
            dt[tot].val=i;
            tot++;
        }
    }
    dt[tot].mul=1;
    dt[tot++].val=25;
    dt[tot].mul=2;
    dt[tot++].val=25;
}

int cnt2(int i,int j) {
    bool x[26];
    memset(x,0,sizeof(x));
    if (dt[i].mul==2) x[dt[i].val]=true;
    if (dt[j].mul==2) x[dt[j].val]=true;
    int ret=0;
    for (int t=0;t<26;t++) ret+=x[t];
    return ret;
}

int cnt3(int i,int j,int k) {
    bool x[26];
    memset(x,0,sizeof(x));
    if (dt[i].mul==2) x[dt[i].val]=true;
    if (dt[j].mul==2) x[dt[j].val]=true;
    if (dt[k].mul==2) x[dt[k].val]=true;
    int ret=0;
    for (int t=0;t<26;t++) ret+=x[t];
    return ret;
}

const int N=100;

int main()
{
    init();
    int ans=0;
    for (int i=0;i<tot;i++) {
        bool flag1=dt[i].mul==2;
        int val1=dt[i].mul*dt[i].val;
        if (flag1&&val1<N) {
            ans++;
        }
        for (int j=i;j<tot;j++) {
            bool flag2=flag1|(dt[j].mul==2);
            int val2=val1+dt[j].mul*dt[j].val;
            if (flag2&&val2<N) {
                ans+=cnt2(i,j);
            }
            for (int k=j;k<tot;k++) {
                bool flag3=flag2|(dt[k].mul==2);
                int val3=val2+dt[k].mul*dt[k].val;
                if (flag3&&val3<N) {
                    ans+=cnt3(i,j,k);
                }
            }
        }
    }
    printf("%d\n",ans);
}
