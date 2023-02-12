
#include <stdio.h>
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

const int N=1000000;
const db PHI=1.61803398874989484820;
const db R5=2.236067977499789;
ll f[N+1];

bool pan(string& str) {
    sort(str.begin(),str.end());
    return str=="123456789";
}

bool check(int x) {
    db logF=x*log10(PHI)-log10(R5);
    int n=(int)(pow(10,logF-floor(logF)+8));
    string tmp=to_string(n);
    return pan(tmp);
}

int main()
{
    f[0]=0;
    f[1]=1;
    for (int i=2;i<N;i++) {
        f[i]=(f[i-1]+f[i-2])%1000000000;
        string str1=to_string(f[i]);
        if (pan(str1)&&check(i)) {
            printf("%d\n",i);
            break;
        }
    }
}