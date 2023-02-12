
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

db poly(db x) {
    return (pow(x,11.0)+1.0)/(x+1.0);
}

db y[15];

db l(int k,int j,db x) {
    db product=1.0;
    for (int i=1;i<=k;i++) {
        if (i==j) continue;
        product=product*(x-i)/(j-i);
    }
    return product;
}

db L(int k,db x) {
    db sum=0.0;
    for (int j=1;j<=k;j++) {
        sum+=y[j]*l(k,j,x);
    }
    return sum;
}

int main()
{
    for (int i=1;i<=10;i++) {
        y[i]=poly(i);
    }
    db ans=0.0;
    for (int i=1;i<=10;i++) {
        ans+=L(i,i+1);
    }
    printf("%.3f\n",ans);
}
