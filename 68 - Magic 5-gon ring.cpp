
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
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

int p[10]={1,2,3,4,5,6,7,8,9,10};
vector<string> vec;
int foo[15]={0,5,6,1,6,7,2,7,8,3,8,9,4,9,5};

void work() {
    int a=p[0]+p[5]+p[6];
    int b=p[1]+p[6]+p[7];
    int c=p[2]+p[7]+p[8];
    int d=p[3]+p[8]+p[9];
    int e=p[4]+p[9]+p[5];
    if (a==b&&b==c&&c==d&&d==e) {
        vector<string> vtmp;
        int mnIdx=0;
        int mn=INF;
        for (int i=0;i<15;i+=3) {
            string tmp=to_string(p[foo[i]])+to_string(p[foo[i+1]])+to_string(p[foo[i+2]]);
            vtmp.pb(tmp);
            int x=10000*p[foo[i]]+100*p[foo[i+1]]+p[foo[i+2]];
            if (x<mn) {
                mn=x;
                mnIdx=i/3;
            }
        }
        string tot;
        for (int i=0;i<vtmp.size();i++) {
            tot+=vtmp[(i+mnIdx)%5];
        }
        vec.pb(tot);
    }
}

void dfs(int start) {
    if (start==10) {
        work();
    } else {
        for (int i=start;i<10;i++) {
            swap(p[start],p[i]);
            dfs(start+1);
            swap(p[start],p[i]);
        }
    }
}

int main() {
    dfs(0);
    sort(vec.begin(),vec.end());
    for (auto& str:vec) printf("%s\n",str.c_str());
}