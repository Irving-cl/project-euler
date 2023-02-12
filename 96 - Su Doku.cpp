
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
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

class DanceLink {
public:
    DanceLink(int n, int m):
        N(n), M(m),
        grid(vector<vector<int>>(n + 1, vector<int>(m + 1, 0))),
        id(vector<vector<int>>(n + 1, vector<int>(m + 1, 0))),
        up(vector<int>((n + 1)*(m + 1), 0)),
        down(vector<int>((n + 1)*(m + 1), 0)),
        leeft(vector<int>((n + 1)*(m + 1), 0)),
        riight(vector<int>((n + 1)*(m + 1), 0)),
        row(vector<int>((n + 1)*(m + 1), 0)),
        col(vector<int>((n + 1)*(m + 1), 0)),
        cnt(vector<int>(m + 1, 0)) {}

    void set_data(vector<vector<int>>& data, int n, int m) {
        if (n != N || m != M) {
            printf("Error setting grid, wrong size!\n");
            return;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                grid[i][j]=data[i][j];
            }
        }
    }

    void init() {
        int tot = -1;
        for (int i = 0; i <= M; i++) {
            id[0][i] = ++tot;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                id[i][j] = ++tot;
                row[tot] = i;
                col[tot] = j;
            }
        }
        // Link Head and C row
        for (int i = 0; i <= M; i++) {
            up[i] = down[i] = i;
            leeft[i] = (i - 1 + M) % M;
            riight[i] = (i + 1) % (M + 1);
        }
        // Add rows
        for (int i = 1; i <= N; i++) {
            add_row(i);
        }
    }

    void dance() {
        ans.clear();
        dance_rec();
    }

    vector<int>& get_ans() {
        return ans;
    }

private:
    int N, M;
    vector<vector<int>> grid;
    vector<vector<int>> id;
    vector<int> up,down,leeft,riight,row,col,cnt;
    vector<int> ans;

    void add_row(int rn) {
        vector<int> vec;
        for (int i = 1; i <= M; i++) {
            if (grid[rn][i] == 1) vec.pb(i);
        }
        if (vec.empty()) return;
        for (int i = 1; i < vec.size(); i++) {
            int x = id[rn][vec[i - 1]];
            int y = id[rn][vec[i]];
            riight[x] = y;
            leeft[y] = x;
            int z = up[vec[i]];
            down[z] = y;
            up[y] = z;
            down[y] = vec[i];
            up[vec[i]] = y;
            cnt[vec[i]]++;
        }
        int last = id[rn][vec.back()];
        int first = id[rn][vec.front()];
        riight[last] = first;
        leeft[first] = last;
        int z = up[vec.front()];
        down[z] = first;
        up[first] = z;
        down[first] = vec.front();
        up[vec.front()] = first;
        cnt[vec.front()]++;
    }

    void remove_col(int cn) {
        leeft[riight[cn]] = leeft[cn];
        riight[leeft[cn]] = riight[cn];
        int x = down[cn];
        while (x != cn) {
            int y = riight[x];
            while (y != x) {
                up[down[y]] = up[y];
                down[up[y]] = down[y];
                cnt[col[y]]--;
                y = riight[y];
            }
            x = down[x];
        }
    }

    void restore_col(int cn) {
        leeft[riight[cn]] = cn;
        riight[leeft[cn]] = cn;
        int x = up[cn];
        while (x != cn) {
            int y = riight[x];
            while (y != x) {
                up[down[y]] = y;
                down[up[y]] = y;
                cnt[col[y]]++;
                y = riight[y];
            }
            x = up[x];
        }
    }

    int find_col_least_cnt() {
        int p = riight[0];
        int ret = p;
        while (p != 0) {
            if (cnt[p] < cnt[ret]) ret = p;
            p = riight[p];
        }
        return ret;
    }

    bool dance_rec() {
        int c1 = riight[0];
        if (c1 == 0) return true;

        c1 = find_col_least_cnt();
        if (cnt[c1] < 1) return false;
        remove_col(c1);

        int x = down[c1];
        while (x != c1) {
            ans.pb(row[x]);

            int y = riight[x];
            while (y != x) {
                remove_col(col[y]);
                y = riight[y];
            }

            if (dance_rec()) return true;

            y = leeft[x];
            while (y != x) {
                restore_col(col[y]);
                y = leeft[y];
            }

            x = down[x];
            ans.pop_back();
        }
        restore_col(c1);
        return false;
    }
};

vector<vector<int>> matrix;
char buf[10];
char sudoku[10][10];
int f1[10][10],f2[10][10],f3[10][10],f4[10][10];
struct node {
    int x,y,val;
} info[1000];

void init() {
    int tot=0;
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            f1[i][j]=++tot;
        }
    }
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            f2[i][j]=++tot;
        }
    }
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            f3[i][j]=++tot;
        }
    }
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            f4[i][j]=++tot;
        }
    }
}

int palace(int x,int y) {
    return (x-1)/3*3+(y-1)/3+1;
}

void build() {
    matrix.clear();
    vector<int> vec(325,0);
    matrix.pb(vec);
    memset(info,0,sizeof(info));
    int idx=1;
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            int num=sudoku[i-1][j-1]-'0';
            if (num!=0) {
                vector<int> vec(325,0);
                vec[f1[i][j]]=1;
                vec[f2[i][num]]=1;
                vec[f3[j][num]]=1;
                vec[f4[palace(i,j)][num]]=1;
                matrix.pb(vec);
                info[idx].x=i;
                info[idx].y=j;
                info[idx].val=num;
                idx++;
            }
        }
    }
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            int num=sudoku[i-1][j-1]-'0';
            if (num==0) {
                for (int k=1;k<=9;k++) {
                    vector<int> vec(325,0);
                    vec[f1[i][j]]=1;
                    vec[f2[i][k]]=1;
                    vec[f3[j][k]]=1;
                    vec[f4[palace(i,j)][k]]=1;
                    matrix.pb(vec);
                    info[idx].x=i;
                    info[idx].y=j;
                    info[idx].val=k;
                    idx++;
                }
            }
        }
    }
}

int main() {
    int res=0;
    for (int i=0;i<50;i++) {
        scanf("%s",buf);
        scanf("%s",buf);
        memset(sudoku,0,sizeof(sudoku));
        for (int i=0;i<9;i++) {
            scanf("%s",sudoku[i]);
        }
        init();
        build();
        DanceLink dl(matrix.size()-1,324);
        dl.set_data(matrix,matrix.size()-1,324);
        dl.init();
        dl.dance();
        vector<int>& ans=dl.get_ans();
        for (int i:ans) {
            sudoku[info[i].x-1][info[i].y-1]=info[i].val+'0';
        }
        int tmp=(sudoku[0][0]-'0')*100+(sudoku[0][1]-'0')*10+(sudoku[0][2]-'0');
        res+=tmp;
    }
    printf("ans:%d\n",res);
}