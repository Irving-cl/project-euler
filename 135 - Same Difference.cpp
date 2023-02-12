
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

using namespace std;

int main()
{
	int ans=0;
	for (int i=1;i<1000000;i++) {
		int cnt=0;
		for (int j=1;j*j<=i;j++) {
			if (i%j==0) {
				int u=j,v=i/j;
				if ((u+v)%4==0) {
					if (3*u>v&&(3*u-v)%4==0) cnt++;
					if (3*v>u&&(3*v-u)%4==0) cnt++;
					if (u==v&&u%2==0) cnt--;
				}
			}
		}
		if (cnt==10) ans++;
	}
	printf("%d\n",ans);
}
