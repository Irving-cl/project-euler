
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

int dp[1<<12];
int num[12];
int n;
string str;

bool check() {
    sort(num,num+n);
    int l=num[0];
    int r=0;
    for (int i=1,j=n-1;i<j;i++,j--) {
        l+=num[i];
        r+=num[j];
        if (l<=r) return false;
    }
    for (int i=0;i<(1<<n);i++) {
        dp[i]=0;
        for (int j=0;j<n;j++) {
            if (i&(1<<j)) dp[i]+=num[j];
        }
    }
    for (int i=1;i<(1<<n);i++) {
        for (int j=i+1;j<(1<<n);j++) {
            if (((i&j)==0)&&dp[i]==dp[j]) return false;
        }
    }    
    return true;
}

int main()
{
    freopen("input.txt","r",stdin);
    int ans=0;
    while (getline(cin,str)) {
        n=0;
        int sum=0;
        int len=str.size();
        for (int i=0;i<len;) {
            int j=i+1;
            int tmp=str[i]-'0';
            while (j<len&&str[j]!=' ') {
                tmp=tmp*10+str[j]-'0';
                j++;
            }
            num[n++]=tmp;
            sum+=tmp;
            i=j+1;
        }
        if (check()) ans+=sum;
    }
    printf("%d\n",ans);
}
