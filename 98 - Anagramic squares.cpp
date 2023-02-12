
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

char buf[20];
vector<string> vec;
vector<ll> mt[2000];
vector<ll> sqrs[20];
unordered_set<ll> us;
map<string,vector<int>> anagram;
ll mx=0;

int len(ll x) {
    int ret=0;
    while (x) {
        ret++;
        x/=10;
    }
    return ret;
}

void gen_sqr() {
    for (int i=1;i<100000;i++) {
        ll tmp=(ll)i*(ll)i;
        us.insert(tmp);
        sqrs[len(tmp)].pb(tmp);
    }
}

bool match(const string& str,ll num) {
    string cmp=to_string(num);
    int tb[26];
    memset(tb,-1,sizeof(tb));
    for (int i=0;i<str.size();i++) {
        char c=str[i];
        char d=cmp[i];
        if (tb[c-'A']==-1) {
            tb[c-'A']=d-'0';
        } else {
            if (tb[c-'A']!=d-'0') return false;
        }
    }
    return true;
}

void get_match() {
    for (int i=0;i<vec.size();i++) {
        int len=vec[i].size();
        for (ll num:sqrs[len]) {
            if (match(vec[i],num)) {
                mt[i].pb(num);
            }
        }
    }
}

bool same_digit(ll a,ll b) {
    string sa=to_string(a);
    string sb=to_string(b);
    sort(sa.begin(),sa.end());
    sort(sb.begin(),sb.end());
    return sa==sb;
}

ll work(const string& a,const string& b,ll num) {
    string c=to_string(num);
    int tb[26];
    memset(tb,-1,sizeof(tb));
    bool vis[10];
    memset(vis,0,sizeof(vis));
    for (int i=0;i<a.size();i++) {
        char p=a[i];
        char q=c[i];
        if (vis[q-'0']) {
            return 2;
        }
        vis[q-'0']=1;
        if (tb[p-'A']==-1) {
            tb[p-'A']=q-'0';
        }
    }
    ll ret=0;
    for (int i=0;i<b.size();i++) {
        int digit=tb[b[i]-'A'];
        if (i==0&&digit==0) return 2;
        ret=ret*10+digit;
    }
    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    gen_sqr();
    while (~scanf("%s",buf)) {
        vec.pb(buf);
        sort(buf,buf+strlen(buf));
        anagram[buf].pb(vec.size()-1);
        memset(buf,0,sizeof(buf));
    }
    get_match();
    for (auto& entry:anagram) {
        vector<int>& v=entry.second;
        for (int i=0;i<v.size();i++) {
            for (int j=i+1;j<v.size();j++) {
                vector<ll>& x=mt[v[i]];
                for (ll ele:x) {
                    ll tmp=work(vec[v[i]],vec[v[j]],ele);
                    if (us.find(tmp)!=us.end()) {
                        mx=max(mx,tmp);
                        mx=max(mx,ele);
                        printf("%s,%lld %s,%lld\n",vec[v[i]].c_str(),ele,vec[v[j]].c_str(),tmp);
                    }
                }
            }
        }
    }
    printf("%lld\n",mx);
}

