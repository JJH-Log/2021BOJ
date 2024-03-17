
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
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, sqrtN, M, Q;
int v[300001], c[10001];

struct Query {
    int s, e, idx;
    bool operator < (Query& x) {
        if (s / sqrtN == x.s / sqrtN) return e < x.e;
        return s / sqrtN < x.s / sqrtN;
    }
};
vector<Query> q;
vector<int> ans;

void oper(int X, bool op) {
    if (op) c[X]++;
    else c[X]--;
}

int check(int len) {
    for (int i = 1; i <= M; i++) {
        if (c[i] > len / 2) return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M; sqrtN = sqrt(N);
    for (int i = 1; i <= N; i++) cin >> v[i];
    cin >> Q;

    q.resize(Q);
    ans.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> q[i].s >> q[i].e;
        q[i].idx = i;
    }
    sort(q.begin(), q.end());

    int sidx, eidx, cidx;
    sidx = q[0].s, eidx = q[0].e, cidx = 0;
    for (int i = q[0].s; i <= q[0].e; i++) oper(v[i], 1);
    ans[q[0].idx] = check(q[0].e - q[0].s + 1);

    for (int i = 1; i < Q; i++) {
        while (sidx < q[i].s) oper(v[sidx++], 0);
        while (eidx > q[i].e) oper(v[eidx--], 0);
        while (sidx > q[i].s) oper(v[--sidx], 1);
        while (eidx < q[i].e) oper(v[++eidx], 1);
        ans[q[i].idx] = check(q[i].e - q[i].s + 1);
    }

    for (int i = 0; i < Q; i++) {
        if (!ans[i]) cout << "no\n";
        else cout << "yes " << ans[i] << '\n';
    }

    return 0;
}