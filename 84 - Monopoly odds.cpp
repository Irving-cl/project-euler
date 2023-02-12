
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

int result[40];

void run() {
    int cnt=0;
    int pos=0;
    int num=0;
    int limit=1000000;
    while (cnt <limit) {
        int r1=rand()%4+1;
        int r2=rand()%4+1;
        pos=(pos+r1+r2)%40;
        if (r1==r2) num+=1;
        else num=0;
        if (pos==2||pos==17||pos==33) {
            int r3=rand()%16+1;
            if (r3==1) pos=0;
            if (r3==2) pos=10;
        }
        if (pos==7||pos==22||pos==36) {
            int r4=rand()%15+1;
            if (r4==1) pos=0;
            if (r4==2) pos=10;
            if (r4==3) pos=11;
            if (r4==4) pos=24;
            if (r4==5) pos=39;
            if (r4==6) pos=5;
            if (r4==7||r4==8) {
                if (pos==7) pos=12;
                if (pos==22) pos=25;
                if (pos==36) pos=5;
            }
            if (r4==9) {
                if (pos==7) pos=12;
                if (pos==22) pos=28;
                if (pos==36) pos=12;
            }
            if (r4==10) pos-=3;
        }
        if (pos==30||num==3) pos=10;
        result[pos]+=1;
        cnt+=1;
        if (num==3) num=0;
    }
}

int main()
{
    run();
    for (int i=0;i<40;i++) {
        printf("%d %d\n",i,result[i]);
    }
}
