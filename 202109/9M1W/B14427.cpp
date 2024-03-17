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
        lld idx, m;
        segNode() :left(nullptr), right(nullptr), idx(100001), m(1e9+1) {}

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
            if (s == e) { idx = s, m = key; return; }
            int mid = (s + e) / 2;
            if (x <= mid) left->update(s, mid, x, key);
            else right->update(mid + 1, e, x, key);
            if ((left->m) > (right->m)) idx = right->idx, m = right->m;
            else idx = left->idx, m = left->m;
            if ((left->m) == (right->m)) idx = min(left->idx, right->idx);
        }
        pair<int, int> query(int s, int e, int l, int r) {
            pair<int, int> ans1, ans2, result;
            if (e < l || r < s) return { 100001, 1e9 + 1 };
            if (l <= s && e <= r) return { idx, m };
            int mid = (s + e) / 2;
            ans1 = left->query(s, mid, l, r);
            ans2 = right->query(mid + 1, e, l, r);
            if (ans1.second > ans2.second) swap(ans1, ans2);
            if (ans1.second == ans2.second) return { min(ans1.first, ans2.first), ans1.second };
            return ans1;
        }
    };
    segNode* root;
    int s, e;
    segTree(int s, int e) : s(s), e(e) { 
        root = new segNode();
        root->init(s, e);
    }
    void update(int x, int key) { root->update(s, e, x, key); }
    pair<int,int> query(int l, int r) { return root->query(s, e, l, r); }
};


int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, q, x, y;
    cin >> N;
    segTree* tree = new segTree(1, N);
    for (i = 1; i <= N; i++) {
        cin >> x;
        tree->update(i, x);
    }
    cin >> M;
    for (i = 0; i < M; i++) {
        cin >> q;
        if (q == 2) cout << tree->query(1, N).first << '\n';
        else {
            cin >> x >> y;
            tree->update(x, y);
        }
    }
    return 0;
}