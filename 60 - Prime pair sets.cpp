
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

const ll N=100000000;

bool p[N+10];
vector<ll> primes;
map<PII,int> m;
map<int,int> freq,lsh,rlsh;
vector<PII> vec;
set<int> cand;
bool conn[20000][20000];

void foo(int x) {
    int left=x;
    int right=0;
    int t=1;
    while (left>10) {
        if (left%10==0) {
            t*=10;
            left/=10;
            continue;
        }
        right+=t*(left%10);
        t*=10;
        left/=10;
        if (!p[left]&&!p[right]) {
            int mn=min(left,right);
            int mx=max(left,right);
            if (++m[mp(mn,mx)]==2) {
                vec.pb(mp(mn,mx));
            }
        }
    }
}

int main() {
    p[1]=1;
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes.pb(i);
        }
        for (int j=0;j<primes.size()&&i*primes[j]<=N;j++) {
            p[i*primes[j]]=1;
            if (i%primes[j]==0) break;
        }
    }

    for (int j=0;j<primes.size();j++) {
        foo(primes[j]);
    }

    for (int i=0;i<vec.size();i++) {
        freq[vec[i].first]++;
        freq[vec[i].second]++;
    }
    int tot=0;
    for (auto& entry:freq) {
        if (entry.second>=4) {
            cand.insert(entry.first);
            lsh[entry.first]=++tot;
            rlsh[tot]=entry.first;
        }
    }

    vector<PII> vec2;
    for (auto& entry:vec) {
        if (cand.find(entry.first)!=cand.end()&&cand.find(entry.second)!=cand.end()) {
            vec2.pb(entry);
            conn[lsh[entry.first]][lsh[entry.second]]=conn[lsh[entry.second]][lsh[entry.first]]=1;
        }
    }

    vector<vector<int>> final;
    for (int i=0;i<vec2.size();i++) {
        for (int j=i+1;j<vec2.size();j++) {
            int a=vec2[i].first,b=vec2[i].second,c=vec2[j].first,d=vec2[j].second;
            if (conn[lsh[a]][lsh[c]]&&conn[lsh[a]][lsh[d]]&&
                conn[lsh[b]][lsh[c]]&&conn[lsh[b]][lsh[d]]) {
                vector<int> tmp;
                tmp.pb(a);tmp.pb(b);tmp.pb(c);tmp.pb(d);
                sort(tmp.begin(),tmp.end());
                final.pb(tmp);
            }
        }
    }

    sort(final.begin(),final.end());
    for (int i=0;i<final.size();i+=3) {
        for (int j=0;j<final[i].size();j++) {
            printf("%d ",final[i][j]);
        }
        printf("\n");
    }

}