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

struct lifeSpan {
    int x, y, s, e;
};
map<pair<int, int>, int> m;
lifeSpan ls[100001];
vector<lifeSpan> ls_log;

vector<pair<int, int>> qs;

struct cnLog {
    int x, y;
    bool raised;
};
int u[100001], dep[100001];
stack<cnLog> st;
int N, M;

int find(int X) {
    if (X == u[X]) return X;
    else return find(u[X]);
}

bool merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) { return false; }
    if (dep[x] < dep[y]) { swap(x, y); }
    u[y] = x;
    if (dep[x] == dep[y]) { dep[x]++; st.push({ x, y, true }); }
    else { st.push({ x, y, false }); }
    return true;
}

void rollback(int cnt) {
    while (cnt--) {
        u[st.top().y] = st.top().y;
        if (st.top().raised) { dep[st.top().x]--; }
        st.pop();
    }
}

struct segTree {
    struct segNode {
        int l, r, cnt;
        vector<pair<int, int>> edges;
        segNode* left, * right;

        segNode(int l, int r) :l(l), r(r), cnt(0) {
            int mid = (l + r) / 2;
            if (l != r) {
                left = new segNode(l, mid);
                right = new segNode(mid + 1, r);
            }
        }
        void update(int s, int e, pair<int, int> edge) {
            if (s <= l && r <= e) {
                edges.push_back(edge);
                return;
            }
            if (r < s || l > e) { return; }
            left->update(s, e, edge);
            right->update(s, e, edge);
            return;
        }

        void doQuery() {
            for (pair<int, int> edge : edges) {
                if (merge(edge.first, edge.second)) cnt++;
            }
            if (l == r) { cout << (find(qs[l].first) == find(qs[l].second)) << '\n'; }
            else {
                left->doQuery();
                right->doQuery();
            }
            rollback(cnt);
            return;
        }
    };

    segNode* root;

    segTree(int l, int r) { root = new segNode(l, r); }
    void update(int s, int e, pair<int, int> edge) { root->update(s, e, edge); }
    void doQuery() { root->doQuery(); }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, qr, x, y, tar;
    int now = 0;
    segTree* tree;
    cin >> N >> M;

    for (i = 0; i < N; i++) u[i] = i;
    for (i = 0; i < M; i++) {
        cin >> qr >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        if (qr == 1) {
            m[{x, y}] = i;
            ls[i] = { x, y, now, -9 };
        }
        else if (qr == 2) {
            tar = m[{x, y}];
            ls[tar].e = now - 1;
            if (ls[tar].s <= ls[tar].e) ls_log.push_back(ls[tar]);
        }
        else if (qr == 3) {
            qs.push_back({ x, y });
            now++;
        }
    }
    if (!now) { return 0; }
    for (i = 0; i < M; i++) {
        if (ls[i].e == -9) {
            ls[i].e = now - 1;
            if (ls[i].s <= ls[i].e) ls_log.push_back(ls[i]);
        }
    }
    tree = new segTree(0, now - 1);
    for (lifeSpan span : ls_log) {
        tree->update(span.s, span.e, { span.x, span.y });
    }
    tree->doQuery();
    return 0;
}