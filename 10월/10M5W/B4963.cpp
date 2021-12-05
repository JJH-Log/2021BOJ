#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct pos {
    int x, y;
};

vector<vector<int>> v;
vector<vector<bool>> vtd;
queue<pos> q;
int N, M;

void bfs(pos S) {
    vtd[S.x][S.y] = 1;
    q.push(S);
    while (!q.empty()) {
        pos now = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                pos next;
                next.x = now.x + "012"[i] - '1';
                next.y = now.y + "012"[j] - '1';
                if (next.x >= 0 && next.x < N && next.y >= 0 && next.y < M && v[next.x][next.y] && !vtd[next.x][next.y]) {
                    vtd[next.x][next.y] = 1;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> M >> N;
        if (!M) break;

        v.resize(N, vector<int>(M, 0));
        vtd.resize(N, vector<bool>(M, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) cin >> v[i][j];
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] && !vtd[i][j]) {
                    result++;
                    bfs({ i, j });
                }
            }
        }
        cout << result << '\n';
        v.clear();
        vtd.clear();
    }
    return 0;
}
