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
#define MOD 10007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct segNode {
    segNode* left, * right;
    lld val, lazy, cnt;
    segNode(int l, int r) :val(0), lazy(0), cnt(0) {
        if (l != r){
            int mid = (l + r) / 2;
            left = new segNode(l, mid);
            right = new segNode(mid + 1, r);
        }
    }
    void update(int l, int r, int s, int e, lld x, lld xcnt) {
        if(s > r || l > e) return;
        else if (s <= l && r <= e) {
            if (l == r) val += x;
            else {
                lazy += x;
                cnt += xcnt;
            }
        }
        else {
            int mid = (l + r) / 2;
            if (lazy) {
                left->update(l, mid, l, mid, lazy, cnt);
                right->update(mid + 1, r, mid + 1, r, lazy + cnt * ((lld)mid - l + 1), cnt);
                lazy = cnt = 0;
            }
            if (s <= mid && mid <= e) {
                left->update(l, mid, s, mid, x, xcnt);
                right->update(mid + 1, r, mid + 1, e, x + ((lld)mid - s + 1) *xcnt, xcnt);
            }
            else {
                left->update(l, mid, s, e, x, xcnt);
                right->update(mid + 1, r, s, e, x, xcnt);
            }
        }
    }
    lld query(int l, int r, int x) {
        if (l > x || r < x) return 0;
        if (l == r) return val;
        int mid = (l + r) / 2;
        if (lazy) {
            left->update(l, mid, l, mid, lazy, cnt);
            right->update(mid + 1, r, mid + 1, r, lazy + cnt * ((lld)mid - l + 1), cnt);
            lazy = cnt = 0;
        }
        return left->query(l, mid, x) + right->query(mid + 1, r, x);
    }
};
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int q, x, y;
    cin >> N;
    segNode* root = new segNode(0, N - 1);
    for (int i = 0; i < N; i++) {
        cin >> x;
        root->update(0, N - 1, i, i, x, 1);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> q >> x;
        if (q == 1) {
            cin >> y;
            root->update(0, N - 1, x - 1, y - 1, 1, 1);
        }
        else {
            cout << root->query(0, N - 1, x - 1) << '\n';
        }
    }



    return 0;
}
