#include<iostream>
#include <cstring>
using namespace std;
char g[105][105], word[105], len;
bool vis[105][105];
int n, m, path[10][3], js;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int cnt, int dir) {
    if (cnt == len) {
        for (int i = 0; i <= js; i++) {
            vis[path[i][0]][path[i][1]] = true;
        }
        return;
    }
    int tx = x + dx[dir];
    int ty = y + dy[dir];
    if (tx > 0 && ty > 0 && tx <= n && ty <= m && g[tx][ty] == word[cnt + 1]) {
        js++;
        path[js][0] = tx;
        path[js][1] = ty;
        dfs(tx, ty, cnt + 1, dir);
    }

}

int main() {
    cin >> n >> m >> word;
    len=(strlen(word)-1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == word[0]) {
                for (int k = 0; k <= 3; k++) {
                    js = 1;
                    path[js][0] = i;
                    path[js][1] = j;
                    dfs(i, j, 0, k);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) {
                cout << g[i][j];
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}