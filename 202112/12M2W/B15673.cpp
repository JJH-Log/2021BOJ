
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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 100002
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N;
int v[BOUND], w[BOUND], rw[BOUND], dp[BOUND];

lld solve() {
    lld result = 0;
    for (int i = 1; i <= N; i++) w[i] = v[i] + w[i - 1];
    for (int i = N; i >= 1; i--) rw[i] = v[i] + rw[i + 1];
    int m, M;
    m = 0;
    for (int i = 1; i <= N; i++) {
        if (w[i] < m) m = w[i];
        dp[i] = max(dp[i - 1], w[i] - m);
    }
    m = M = 0;
    for (int i = N; i > 1; i--) {
        if (rw[i] < m) m = rw[i];
        M = max(M, rw[i] - m);
        result = max(result, (lld)M * dp[i - 1]);
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> v[i];
    
    lld r1, r2;
    r1 = solve();
    for (int i = 1; i <= N; i++) v[i] *= -1;
    r2 = solve();

    if (N == 2 && v[1] * v[2] < 0) cout << v[1] * v[2];
    else cout << max(r1, r2);

    return 0;
}