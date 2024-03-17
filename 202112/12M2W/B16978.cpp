
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

struct segTree {
    segTree* left, * right;
    lld val;
    segTree(int l, int r):val(0){
        if (l != r) {
            int mid = (l + r) / 2;
            left = new segTree(l, mid);
            right = new segTree(mid + 1, r);
        }
    }

    void update(int l, int r, int x, int key) {
        if (l > x || x > r) return;
        if (l == x && r == x) val = key;
        else {
            int mid = (l + r) / 2;
            left->update(l, mid, x, key);
            right->update(mid + 1, r, x, key);
            val = left->val + right->val;
        }
    }

    lld query(int l, int r, int s, int e) {
        if (s > r || l > e) return 0;
        if (s <= l && r <= e) return val;
        int mid = (l + r) / 2;
        return left->query(l, mid, s, e) + right->query(mid + 1, r, s, e);
    }
};

struct info {
    int op, idx, s, e;
    bool operator < (info& x) {
        return op < x.op;
    }
};


int N, Q;
vector<pii> q1;
vector<info> q2;
vector<lld> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    segTree* root;
    cin >> N;
    root = new segTree(1, N);

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        root->update(1, N, i, x);
    }

    cin >> Q;
    ans.resize(Q, -1);
    for (int i = 0; i < Q; i++) {
        int k, x, y, z;
        cin >> k >> x >> y;
        if (k == 1) q1.push_back({ x, y });
        else {
            cin >> z;
            q2.push_back({ x, i, y, z });
        }
    }
    sort(q2.begin(), q2.end());

    int cnt = 0;
    for (int i = 0; i < q2.size(); i++) {
        while (cnt < q2[i].op) {
            root->update(1, N, q1[cnt].first, q1[cnt].second);
            cnt++;
        }
        ans[q2[i].idx] = root->query(1, N, q2[i].s, q2[i].e);
    }

    for (int i = 0; i < Q; i++) if (ans[i] != -1) cout << ans[i] << '\n';

    return 0;
}