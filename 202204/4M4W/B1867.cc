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

vector<int> w[501];
int N, K, x, y, res, q[501];
bool vtd[500];

bool bipartite(int now) {
    vtd[now] = true;
    for (auto tar : w[now]) {
        if (q[tar] == -1 || !vtd[q[tar]] && bipartite(q[tar])) {
            q[tar] = now;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        w[x].push_back(y);
    }
    fill(q + 1, q + N + 1, -1);
    for (int i = 1; i <= N; i++) {
        fill(vtd + 1, vtd + N + 1, false);
        if (bipartite(i)) res++;
    }
    cout << res;

    return 0;
}