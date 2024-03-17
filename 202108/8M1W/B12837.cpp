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
        int l, r, mid;
        segNode* left, *right;

        segNode(int l, int r) : l(l), r(r), val(0) {
            mid = (l + r) / 2;
            if (l != r) {
                left = new segNode(l, mid);
                right = new segNode(mid + 1, r);
            }
        }

        void insert(int X, int key) {
            val += key;
            if (l != r) {
                if (X <= mid) left->insert(X, key);
                else right->insert(X, key);
            }
        }

        lld query(int lo, int hi) {
            if (hi < l || r < lo) return 0;
            if (lo <= l && r <= hi) return val;
            else return left->query(lo, hi) + right->query(lo, hi);
        }
    };

    segNode* root;

    segTree(int len) : root(new segNode(0, len)) {}

    void insert(int X, int key) { root->insert(X, key); }
    lld query(int lo, int hi) { return root->query(lo, hi); }
};


int N, Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    segTree* tree = new segTree(N);
    
    int i, q, x, y;
    for (i = 0; i < Q; i++) {
        cin >> q >> x >> y;
        if (q == 1) tree->insert(x - 1, y);
        else cout << tree->query(x - 1, y - 1) << '\n';
    }

    return 0;
}