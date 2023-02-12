
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

ll gcd(ll a,ll b) {
    return b==0?a:gcd(b,a%b);
}

bool coprime(ll x,ll y) {
    return gcd(x,y)==1;
}

int cal(int M) {
    int sum=0;
    for (int m=2;m*2<=M;m++) {
        for (int n=m-1;n>=1;n-=2) {
            if (!coprime(m,n)) continue;
            int a=2*m*n;
            int b=m*m-n*n;
            int mx=max(a,b);
            int mn=min(a,b);
            if (mn>M) continue;
            // c=mn,a+b=mx
            int mul_mn=mn;
            int mul_mx=mx;
            while (mul_mn<=M) {
                sum+=max(0,mul_mn-(mul_mx/2+mul_mx%2)+1);
                mul_mn+=mn;
                mul_mx+=mx;
            }
            // c=mx,a+b=mn
            if (mx<=M) {
                int mul_mx=mx;
                int mul_mn=mn;
                while (mul_mx<=M) {
                    sum+=mul_mn/2;
                    mul_mn+=mn;
                    mul_mx+=mx;
                }

            }
        }
    }
    return sum;
}

int main()
{
    int lo=1,hi=10000;
    while (lo<hi) {
        int mid=(lo+hi)>>1;
        if (cal(mid)<=1000000) {
            lo=mid+1;
        } else {
            hi=mid;
        }
    }
    printf("lo:%d %d\n",lo,cal(lo));
}
