
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

const int N=5000010;
const ll MX=1000000000;
int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll ham[N];
int idx[25]={0};
int tot=1;

int main()
{
    ham[0]=1;
    while (true) {
        ll mn=MX+1;
        for (int i=0;i<25;i++) {
            mn=min(mn,ham[idx[i]]*primes[i]);
        }
        if (mn>MX) break;
        ham[tot++]=mn;
        for (int i=0;i<25;i++) {
            if (mn==ham[idx[i]]*primes[i]) idx[i]++;
        }
    }
    printf("ans:%d\n",tot);
}
