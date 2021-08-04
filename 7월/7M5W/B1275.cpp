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


struct segTree {
    struct segNode {
        int l, r, mid;
        lld val;
        segNode* left, * right;
        segNode(int l, int r) :l(l), r(r), val(0) {
            mid = (l + r) / 2;
            if (l != r) {
                left = new segNode(l, mid);
                right = new segNode(mid + 1, r);
            }
        }
        void update(int x, int q) {
            if (l != r) {
                if (x <= mid) left->update(x, q);
                else right->update(x, q);
                val = left->val + right->val;
                return;
            }
            else val = q;
        }
        lld query(int lo, int hi) {
            if (lo > hi) return query(hi, lo);
            if (r < lo || l > hi) return 0;
            if (lo <= l && r <= hi) return val;
            return (left->query(lo, hi) + right->query(lo, hi));
        }
    };
    segNode* root;
    segTree(int nSize) : root(new segNode(0, nSize - 1)) {}
    void update(int x, int q) { root->update(x, q); }
    lld query(int lo, int hi) { return root->query(lo, hi); }
};
int N, Q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i, temp, x, y;
    cin >> N >> Q;
    segTree T = segTree(N);
    for (i = 0; i < N; i++) {
        cin >> temp;
        T.update(i, temp);
    }
    for (i = 0; i < Q; i++) {
        cin >> x >> y;
        cout << T.query(x - 1, y - 1) << '\n';
        cin >> x >> y;
        T.update(x - 1, y);
    }
    

    return 0;
}