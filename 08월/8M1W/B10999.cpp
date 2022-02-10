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
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct segTree{
    struct segNode {
        lld val;
        lld lazy;
        int l, r, mid;
        segNode* left, *right;

        segNode(int l, int r) : l(l), r(r), val(0), lazy(0) {
            mid = (l + r) / 2;
            if (l != r) {
                left = new segNode(l, mid);
                right = new segNode(mid + 1, r);
            }
        }

        void update_range(lld key, int lo, int hi) {
            if (hi < l || r < lo) return;
            if (lo <= l && r <= hi) {
                val += ((lld)r - l + 1) * key;
                if (l != r) lazy += key;
            }
            else {
                if (lazy) {
                    left->update_range(lazy, l, mid);
                    right->update_range(lazy, mid + 1, r);
                    lazy = 0;
                }
                left->update_range(key, lo, hi);
                right->update_range(key, lo, hi);
                val = left->val + right->val;
            }
        }

        lld query(int lo, int hi) {
            if (hi < l || r < lo) return 0;
            if (lo <= l && r <= hi) return val;
            else {
                if (lazy) {
                    left->update_range(lazy, l, mid);
                    right->update_range(lazy, mid + 1, r);
                    lazy = 0;
                }
                return left->query(lo, hi) + right->query(lo, hi);
            }
        }
    };

    segNode* root;

    segTree(int len) : root(new segNode(0, len)) {}

    void update_range(int key, int lo, int hi) { root->update_range(key, lo, hi); }
    lld query(int lo, int hi) { return root->query(lo, hi); }
};


int N, M, K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    segTree* tree = new segTree(N);
    
    int i, q, x, y, d;
    for (i = 0; i < N; i++) {
        cin >> x;
        tree->update_range(x, i, i);
    }
    for (i = 0; i < M + K; i++) {
        cin >> q;
        if (q == 1) {
            cin >> x >> y >> d;
            tree->update_range(d, x - 1, y - 1);
        }
        else {
            cin >> x >> y;
            cout << tree->query(x - 1, y - 1) << '\n';
        }
    }

    return 0;
}