
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

const ll MX=1000000000000000;
vector<ll> vec;

ll sum(ll x) {
    ll ret=0;
    while (x>0) {
        ret+=(x%10);
        x/=10;
    }
    return ret;
}

void work(ll x) {
    ll num=x;
    while (true) {
        num*=x;
        if (num>=MX) break;
        if (num>10) {
            if (sum(num)==x) vec.pb(num);
        }
    }
}

int main()
{
    for (int i=2;i<=90;i++) {
        work(i);
    }
    sort(vec.begin(),vec.end());
    for (int i=0;i<vec.size();i++) {
        printf("idx:%d %lld\n",i+1,vec[i]);
    }
}
