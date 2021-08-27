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
#define MOD 10007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int N, M;
vector<int> v;

pair<int, int> assign(pair<int, int> A, pair<int, int> B) {
    return { min(A.first, B.first), max(A.second, B.second) };
}

struct segTree {
    struct segNode {
        int l, r, mid;
        pair<int, int> val; //min & max
        segNode* left, *right;
        segNode(int l, int r) :l(l), r(r), val({ N + 1, 0 }) {
            mid = (l + r) / 2;
            if (l != r) {
                left = new segNode(l, mid);
                right = new segNode(mid + 1, r);
            }
        }

        void update(int X, int key) {
            if (l == r) {
                if (l == X) val = { key, key };
                else return;
            }
            else if (l <= X && X <= r) {
                left->update(X, key);
                right->update(X, key);
                val = { min(left->val.first, right->val.first), max(left->val.second, right->val.second) };
                return;
            }
        }
        pair<int, int> query(int x, int y) {
            if (x <= l && r <= y) return val;
            if (r < x || y < l) return { N + 1, 0 };
            else return assign(left->query(x, y), right->query(x, y));
        }
    };

    segNode* root;
    segTree(int l, int r) { root = new segNode(l, r); }

    void update(int X, int key) { root->update(X, key); }
    pair<int, int> query(int x, int y) { return root->query(x, y); }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, x, y, a, b, qr;
    pair<int, int> ans;
    cin >> N >> M;
    segTree* tree = new segTree(1, N);

    v.resize(N + 1, 0);
    for (i = 0; i < N; i++) {
        cin >> x;
        v[i + 1] = x;
        tree->update(x, i + 1);
    }
    for (i = 0; i < M; i++) {
        cin >> qr >> x >> y;
        if (qr == 1) {
            a = v[x];
            b = v[y];
            v[x] = b;
            v[y] = a;
            tree->update(b, x);
            tree->update(a, y);
        }
        if (qr == 2) {
            ans = tree->query(x, y);
            if (ans.second - ans.first == y - x) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}