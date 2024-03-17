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
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct segNode {
    int val;
    segNode* left, * right;
    segNode(int l, int r) :val(0) {
        if (l != r) {
            int mid = (l + r) / 2;
            left = new segNode(l, mid);
            right = new segNode(mid + 1, r);
        }
    }
    void update(int l, int r, int x, int key) {
        if (x < l || x > r) return;
        if (l == r) {
            val = key;
            return;
        }
        int mid = (l + r) / 2;
        left->update(l, mid, x, key);
        right->update(mid + 1, r, x, key);
        val = left->val + right->val;
    }
    int query(int l, int r, int s, int e) {
        if (s <= l && r <= e) return val;
        if (s > r || l > e) return 0;
        int mid = (l + r) / 2;
        return left->query(l, mid, s, e) + right->query(mid + 1, r, s, e);
    }
};

vector<int> now;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, T, x, idx;
    cin >> T;
    while (T--) {
        cin >> N >> M;

        now.resize(N, 0);
        for (int i = 0; i < N; i++) now[i] = N - 1 - i;

        segNode* root = new segNode(0, N + M - 1);
        for (int i = 0; i < N; i++) root->update(0, N + M - 1, i, 1);

        for (int i = 0; i < M; i++) {
            cin >> x, x--;
            idx = now[x], now[x] = N + i;
            cout << root->query(0, N + M - 1, idx + 1, N + M - 1) << ' ';
            root->update(0, N + M - 1, idx, 0);
            root->update(0, N + M - 1, N + i, 1);
        }
        cout << '\n';
    }
    return 0;
}