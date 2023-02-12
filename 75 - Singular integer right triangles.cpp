
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

int cnt[1500010];

int calc(int m,int n) {
    return 2*m*(m+n);
}

int gcd(int a,int b) {
    return b==0?a:gcd(b,a%b);
}

int main()
{
    for (int i=1;calc(i+1,i)<=1500000;i++) {
        for (int j=i+1;calc(j,i)<=1500000;j+=2) {
            if (gcd(i,j)==1) {
                int l=calc(j,i);
                int tmp=l;
                while (tmp<=1500000) {
                    cnt[tmp]++;
                    tmp+=l;
                }
            }
        }
    }
    int ans=0;
    for (int i=1;i<=1500000;i++) {
        if (cnt[i]==1) ans++;
    }
    printf("%d\n",ans);
}