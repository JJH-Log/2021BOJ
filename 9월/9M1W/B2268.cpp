#define _CRT_SECURE_NO_WARNINGS
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
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct segTree {
    struct segNode {
        segNode* left, * right;
        lld val;
        segNode() :left(nullptr), right(nullptr), val(0) {}

        void init(int s, int e) {
            if (s != e) {
                int mid = (s + e) / 2;
                left = new segNode();
                right = new segNode();
                left->init(s, mid);
                right->init(mid + 1, e);
            }
        }
        void update(int s, int e, int x, int key) {
            if (s == e) { val = key; return; }
            int mid = (s + e) / 2;
            if (x <= mid) left->update(s, mid, x, key);
            else right->update(mid + 1, e, x, key);
            val = left->val + right->val;
        }
        lld query(int s, int e, int l, int r) {
            if (e < l || r < s) return 0;
            if (l <= s && e <= r) return val;
            int mid = (s + e) / 2;
            return left->query(s, mid, l, r) + right->query(mid + 1, e, l, r);
        }
    };
    segNode* root;
    int s, e;
    segTree(int s, int e) : s(s), e(e) { 
        root = new segNode();
        root->init(s, e);
    }
    void update(int x, int key) { root->update(s, e, x, key); }
    lld query(int l, int r) { return root->query(s, e, l, r); }
};


int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, q, x, y;
    cin >> N >> M;
    segTree* tree = new segTree(1, N);
    for (i = 0; i < M; i++) {
        cin >> q >> x >> y;
        if (!q) {
            if (x > y) swap(x, y);
            cout << tree->query(x, y) << '\n';
        }
        else tree->update(x, y);
    }
    return 0;
}