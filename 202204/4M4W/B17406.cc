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
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct order {
    int r, c, s;
};

int N, M, K, res, v[51][51], cp[51][51];
pii mv[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
order k[6];

int w[6];
bool lock[6];

int getMin() {
    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 1; j <= M; j++) tmp += cp[i][j];
        ans = min(ans, tmp);
    }
    return ans;
}

void turn_cw(int r, int c, int s) {
    int x, y, dx, dy, d, cnt, tmp;
    for (int t = 1; t <= s; t++) {
        x = r - t, y = c - t;
        tmp = cp[x][y];
        d = 0;
        
        while (d < 4) {
            cnt = 2 * t;
            while (cnt--) {
                dx = x + mv[d].first;
                dy = y + mv[d].second;
                cp[x][y] = cp[dx][dy];
                x = dx, y = dy;
            }
            d++;
        }
        cp[r - t][c - t + 1] = tmp;
    }
}

void backTracking(int cnt) {
    if (cnt == K) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) cp[i][j] = v[i][j];
        }
        for (int i = 0; i < K; i++) {
            order now = k[w[i]];
            turn_cw(now.r, now.c, now.s);
        }
        res = min(res, getMin());
        return;
    }

    for (int i = 0; i < K; i++) {
        if (!lock[i]) {
            lock[i] = true;
            w[cnt] = i;
            backTracking(cnt + 1);
            lock[i] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cin >> v[i][j];
    }
    for (int i = 0; i < K; i++) cin >> k[i].r >> k[i].c >> k[i].s;
    res = 1e9;
    backTracking(0);
    cout << res;

    return 0;
}