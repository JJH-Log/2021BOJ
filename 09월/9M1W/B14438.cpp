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
#define MOD 100000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct segNode {
    segNode *left, *right;
    int val;
    segNode(int s, int e) :val(1e9 + 1) {
        int mid = (s + e) / 2;
        if (s != e) {
            left = new segNode(s, mid);
            right = new segNode(mid + 1, e);
        }
    }
    void update(int s, int e, int x, int key) {
        if (s == e) { val = key; return; }
        int mid = (s + e) / 2;
        if (x <= mid) left->update(s, mid, x, key);
        else right->update(mid + 1, e, x, key);
        val = min(left->val, right->val);
    }
    int query(int s, int e, int l, int r) {
        if (r < s || e < l) return 1e9 + 1;
        if (l <= s && e <= r) return val;
        int mid = (s + e) / 2;
        return min(left->query(s, mid, l, r), right->query(mid + 1, e, l, r));
    }
};
int N, M;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i, q, x, y;
    cin >> N;
    segNode* tree = new segNode(0, N - 1);
    for (i = 0; i < N; i++) {
        cin >> x;
        tree->update(0, N - 1, i, x);
    }
    cin >> M;
    for (i = 0; i < M; i++) {
        cin >> q >> x >> y;
        if (q == 1) tree->update(0, N - 1, x - 1, y);
        if (q == 2) cout << tree->query(0, N - 1, x - 1, y - 1) << '\n';
    }

    return 0;
}