
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

const int N=50;
ll a[4]={1,2,4,8};

int main()
{
    for (int i=5;i<=N;i++) {
        ll tmp=a[0]+a[1]+a[2]+a[3];
        a[0]=a[1];
        a[1]=a[2];
        a[2]=a[3];
        a[3]=tmp;
    }
    printf("%lld\n",a[3]);
}
