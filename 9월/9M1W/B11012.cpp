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

struct segNode {
    segNode* left, * right;
    int val;
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
    void update(segNode* before, int s, int e, int x) {
        if (s == e) { val = before->val + 1; return; }
        int mid = (s + e) / 2;
        val = before->val + 1;
        if (x <= mid) {
            left = new segNode(); right = before->right;
            left->update(before->left, s, mid, x);
        }
        else {
            left = before->left; right = new segNode();
            right->update(before->right, mid + 1, e, x);
        }
    }
    int query(int s, int e, int l, int r) {
        if (e < l || r < s) return 0;
        if (l <= s && e <= r) { return val; }
        int mid = (s + e) / 2;
        return left->query(s, mid, l, r) + right->query(mid + 1, e, l, r);
    }
};


vector<pair<int, int>> v;
vector<int> vx;
vector<segNode*> vs;
int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("PG.in.txt", "r", stdin);
    //FILE* pFile = fopen("test.txt", "w");
    int i, x1, y1, x2, y2, T;
    int tar1, tar2;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        v.resize(N, { 0, 0 });
        vx.resize(N);
        vs.resize(N);
        for (i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        for (i = 0; i < N; i++) {
            vx[i] = v[i].first;
            vs[i] = new segNode();
        }
        segNode* root = new segNode();
        root->init(0, 100000);
        vs[0]->update(root, 0, 100000, v[0].second);
        for (i = 1; i < N; i++) vs[i]->update(vs[i - 1], 0, 100000, v[i].second);
        lld result = 0;
        for (i = 0; i < M; i++) {
            cin >> x1 >> x2 >> y1 >> y2;
            tar1 = lower_bound(vx.begin(), vx.end(), x1) - vx.begin();
            tar2 = upper_bound(vx.begin(), vx.end(), x2) - vx.begin();
            if (tar2 > 0) result += vs[tar2 - 1]->query(0, 100000, y1, y2);
            if (tar1 > 0) result -= vs[tar1 - 1]->query(0, 100000, y1, y2);
        }
        cout << result << '\n';
        //fprintf(pFile, "%lld\n", result);
        v.clear();
        vx.clear();
        vs.clear();
    }
    return 0;
}