
#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

int period(int n)
{
    set<PII> s;
    int a=1,b=n,c=(int)sqrt((db)n);
    while (s.find(mp(a,c))==s.end()) {
        s.insert(mp(a,c));
        int x=(int)((db)a/(sqrt((db)b)-c));
        int _a=(b-c*c)/a;
        int _c=(b*x-c*c*x-a*c)/a;
        a=_a;c=_c;
    }
    return s.size();
}

int main()
{
    set<int> square;
    for (int i=1;i<=100;i++) square.insert(i*i);
    int ans=0;
    for (int i=2;i<=10000;i++) {
        if (square.find(i)==square.end()&&period(i)%2==1) {
            ans++;
        }
    }
    printf("%d\n",ans);
}