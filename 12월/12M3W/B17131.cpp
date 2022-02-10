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
#define MOD 1000000007
#define BOUND 100002
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct pos {
    int x, y;
    bool operator < (const pos& X) const {
        if (x == X.x) return y < X.y;
        return x < X.x;
    }
};

struct segTree {
    segTree* left, * right;
    int val;
    segTree(int l, int r):val(0) {
        if (l != r) {
            int mid = (l + r) / 2;
            left = new segTree(l, mid);
            right = new segTree(mid + 1, r);
        }
    }
    void update(int l, int r, int x, int key) {
        if (l > x || r < x) return;
        if (l == x && r == x) {
            val += key;
            return;
        }
        else {
            int mid = (l + r) / 2;
            left->update(l, mid, x, key);
            right->update(mid + 1, r, x, key);
            val = left->val + right->val;
        }
    }
    int query(int l, int r, int s, int e) {
        if (s > r || l > e) return 0;
        if (s <= l && r <= e) return val;
        int mid = (l + r) / 2;
        return left->query(l, mid, s, e) + right->query(mid + 1, r, s, e);
    }
};
int N, l[200000], r[200000];
segTree* ltree, * rtree;
vector<pos> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i].x >> v[i].y;
    sort(v.begin(), v.end());
    ltree = new segTree(0, 400002);
    rtree = new segTree(0, 400002);

    int ib;
    ib = 0;
    for (int i = 1; i < N; i++) {
        while (v[ib].x != v[i].x) ltree->update(0, 400002, v[ib].y + 200000, 1), ib++;
        l[i] = ltree->query(0, 400002, v[i].y + 200000 + 1, 400002);
    }
    ib = N - 1;
    for (int i = N - 2; i > 0; i--) {
        while (v[ib].x != v[i].x) rtree->update(0, 400002, v[ib].y + 200000, 1), ib--;
        r[i] = rtree->query(0, 400002, v[i].y + 200000 + 1, 400002);
    }
    lld result = 0;
    for (int i = 0; i < N; i++) result = (result + (lld)l[i] * r[i]) % MOD;
    cout << result;

    return 0;
}