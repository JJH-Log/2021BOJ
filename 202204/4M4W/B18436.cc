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

int N, Q, v[100001];
int tree[2][100001]; //even, odd

void update(int op, int x, int key) {
    for (int i = x; i <= N; i += i & -i) tree[op][i] += key;
}

int query(int op, int x) {
    int ans = 0;
    for (int i = x; i; i -= i & -i) ans += tree[op][i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        update(v[i] % 2, i, 1);
    }
    cin >> Q;
    int q, a, b;
    for (int i = 1; i <= Q; i++) {
        cin >> q >> a >> b;
        if (q == 1) {
            if (v[a] % 2 != b % 2) {
                update(v[a] % 2, a, -1);
                update(b % 2, a, 1);
                v[a] = b;
            }
        }
        else cout << query(q % 2, b) - query(q % 2, a - 1) << '\n';
    }


    return 0;
}