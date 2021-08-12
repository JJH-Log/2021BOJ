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
    int op;
};

vector<vector<char>> v;
queue<pos> q;
int N;
int M, m;


int toNum(char X) {
    return X - '0';
}

int toOp(char X) {
    if (X == '+') return 1;
    if (X == '-') return 2;
    if (X == '*') return 3;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    cin >> N;
    v.resize(N, vector<char>(N, 0));
    M = -1e9, m = 1e9;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) cin >> v[i][j];
    }

    q.push({ 0, 0, toNum(v[0][0]), 0 });

    int x, y, d, op, dx, dy;
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        d = q.front().d;
        op = q.front().op;
        q.pop();
        if (x == N - 1 && y == N - 1) {
            if (d > M) M = d;
            if (d < m) m = d;
        }
        for (i = 0; i < 2; i++) {
            dx = x + "21"[i] - '1';
            dy = y + "12"[i] - '1';
            if (dx < N && dy < N) {
                if ((dx + dy) % 2) q.push({ dx, dy, d, toOp(v[dx][dy]) });
                else {
                    if (op == 1) q.push({ dx, dy, d + toNum(v[dx][dy]), 0 });
                    if (op == 2) q.push({ dx, dy, d - toNum(v[dx][dy]), 0 });
                    if (op == 3) q.push({ dx, dy, d * toNum(v[dx][dy]), 0 });
                }
            }
        }
    }
    cout << M << ' ' << m;
    return 0;
}