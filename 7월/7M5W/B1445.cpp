#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct pos {
    int x;
    int y;
    int d;
};

struct cmp {
    bool operator()(pos& A, pos& B) {
        return A.d > B.d;
    }
};

priority_queue<pos, vector<pos>, cmp> pq;
vector<vector<int>> v;
vector<vector<int>> w;
int N, M;
pair<int, int> S, F;

bool isIn(int x, int y) {
    return (x >= 0) && (x < N) && (y >= 0) && (y < M);
}

int getValue(int x, int y) {
    if (x == S.first && y == S.second) return 0;
    if (x == F.first && y == F.second) return 0;
    if (v[x][y] == 10000) return 10000;
    int result = 0;
    for (int i = 0; i < 4; i++) {
        int dx = x + "2011"[i] - '1';
        int dy = y + "1120"[i] - '1';
        if (isIn(dx, dy) && v[dx][dy] == 10000) return 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    string s;
    cin >> N >> M;
    v.resize(N, vector<int>(M, 0));
    w.resize(N, vector<int>(M, -1));

    for (i = 0; i < N; i++) {
        cin >> s;
        for (j = 0; j < M; j++) {
            if (s[j] == 'g') v[i][j] = 10000;
            if (s[j] == 'S') {
                S = { i, j };
                w[i][j] = 0;
                pq.push({ i, j, 0 });
            }
            if (s[j] == 'F') F = { i, j };
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            v[i][j] = getValue(i, j);
        }
    }

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int d = pq.top().d;
        pq.pop();
        if (d == w[x][y]) {
            for (i = 0; i < 4; i++) {
                int dx = x + "2011"[i] - '1';
                int dy = y + "1120"[i] - '1';
                if (isIn(dx, dy)) {
                    if (w[dx][dy] == -1 || w[dx][dy] > w[x][y] + v[dx][dy]) {
                        w[dx][dy] = w[x][y] + v[dx][dy];
                        pq.push({ dx, dy, w[dx][dy] });
                    }
                }
            }
        }
    }
    cout << w[F.first][F.second] / 10000 << ' ' << w[F.first][F.second] % 10000;

    return 0;
}