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
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;



struct segTree {
    lld val;
    lld lazy;
    segTree* left, * right;

    segTree(int l, int r) : val(0), lazy(0) {
        int mid = (l + r) / 2;
        if (l != r) {
            left = new segTree(l, mid);
            right = new segTree(mid + 1, r);
        }
    }

    void update_range(int l, int r, int s, int e, lld key) {
        if (s > r || l > e) return;
        if (s <= l && r <= e) {
            val += ((lld)r - l + 1) * key;
            if (l != r) lazy += key;
        }
        else {
            int mid = (l + r) / 2;
            if (lazy) {
                left->update_range(l, mid, l, mid, lazy);
                right->update_range(mid + 1, r, mid + 1, r, lazy);
                lazy = 0;
            }
            left->update_range(l, mid, s, e, key);
            right->update_range(mid + 1, r, s, e, key);
            val = left->val + right->val;
        }
    }

    lld query(int l, int r, int s, int e) {
        if (s > r || l > e) return 0;
        if (s <= l && r <= e) return val;
        else {
            int mid = (l + r) / 2;
            if (lazy) {
                left->update_range(l, mid, l, mid, lazy);
                right->update_range(mid + 1, r, mid + 1, r, lazy);
                lazy = 0;
            }
            return left->query(l, mid, s, e) + right->query(mid + 1, r, s, e);
        }
    }
};
segTree* tree;

int N, M, K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    
    tree = new segTree(1, N);
    lld i, q, x, y, d;
    for (i = 1; i <= N; i++) {
        cin >> x;
        tree->update_range(1, N, i, i, x);
    }
    for (i = 0; i < M + K; i++) {
        cin >> q;
        if (q == 1) {
            cin >> x >> y >> d;
            tree->update_range(1, N, x, y, d);
        }
        else {
            cin >> x >> y;
            cout << tree->query(1, N, x, y) << '\n';
        }
    }

    return 0;
}