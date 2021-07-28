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
        int val;
        segNode *left, *right;
        segNode(int l, int r) : l(l), r(r), val(0) {
            mid = (l + r) / 2;
            if (l != r) {
                left = new segNode(l, mid);
                right = new segNode(mid + 1, r);
            }
        }

        void update(int x, int q) {
            if (l == r) val = q;
            else {
                if (x <= mid) left->update(x, q);
                else right->update(x, q);
                val = max(left->val, right->val);
            }
        }

        int query(int lo, int hi) {
            if (hi < l || r < lo) return -1;
            if (lo <= l && r <= hi) return val;
            return max(left->query(lo, hi), right->query(lo, hi));
        }
    };

    segNode* root;
    segTree(int nSize) : root(new segNode(0, nSize)) {};

    void update(int x, int q) { root->update(x, q); }
    int query(int lo, int hi) { return root->query(lo, hi); }
    
};

vector<segTree> segTrees; //segTree composed by HLD
vector<vector<pair<int, int>>> cost; 
vector<vector<int>> w; 
vector<pair<int, int>> E;
vector<int> hc; 
vector<int> hs; 
vector<int> hp; 
vector<int> hd;
vector<int> ht; 
vector<int> hn;
vector<bool> vtd; 
vector<int> hin;
vector<int> hout;
vector<int> hm;
int N, dfsn;

void initHLD() {
    hc.resize(N, 0);
    hs.resize(N);
    hp.resize(N);
    hd.resize(N, 0);
    ht.resize(N);
    hm.resize(N);
    hn.resize(N);
    vtd.resize(N);
    w.resize(N);
    cost.resize(N);
    dfsn = 0;
}

void dfsMakeTree(int now) {
    vtd[now] = true;
    for (auto& next : cost[now]) {
        if (vtd[next.first]) continue;
        w[now].push_back(next.first);
        hc[next.first] = next.second;
        dfsMakeTree(next.first);
    }
    return;
}

void dfsCntSub(int now) {
    hs[now] = 1;
    for (auto& next : w[now]) {
        hp[next] = now;
        hd[next] = hd[now] + 1;
        dfsCntSub(next);
        hs[now] += hs[next];
        if (hs[next] > hs[w[now][0]]) swap(next, w[now][0]);
    }
}

void dfsGetTop(int now) {
    hn[now] = ++dfsn;
    for (auto& next : w[now]) {
        if (next == w[now][0]) ht[next] = ht[now];
        else ht[next] = next;
        dfsGetTop(next);
    }
    hd[now] = hd[now] - hd[ht[now]]; //keep gap
}

void initSegTree(int now) {
    for (auto& next : w[now]) initSegTree(next);
    if (!w[now].size()) {
        segTrees.push_back(segTree(hd[now]));
        hm[ht[now]] = segTrees.size() - 1;
    }
    segTrees[hm[ht[now]]].update(hd[now], hc[now]);
}

int getMax(int u, int v) {
    if (u == v) return 0;
    if (ht[u] == ht[v]) {
        if (hd[u] > hd[v]) return getMax(v, u);
        else return segTrees[hm[ht[u]]].query(hd[u] + 1, hd[v]);
    }
    else {
        if (hn[ht[u]] < hn[ht[v]])  return getMax(v, u);
        else return max(segTrees[hm[ht[u]]].query(0, hd[u]), getMax(hp[ht[u]], v));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, M, x, y, d;
    cin >> N;
    initHLD();
    for (i = 1; i < N; i++) {
        cin >> x >> y >> d;
        x--, y--;
        cost[x].push_back({ y, d });
        cost[y].push_back({ x, d });
        E.push_back({ x, y });
    }
    
    dfsMakeTree(0);
    dfsCntSub(0);
    dfsGetTop(0);
    initSegTree(0);

    cin >> M;
    for (i = 0; i < M; i++) {
        int tNum;
        cin >> d >> x >> y;
        if (d == 1) {
            x--;
            if (hn[E[x].first] > hn[E[x].second]) segTrees[hm[ht[E[x].first]]].update(hd[E[x].first], y);
            else segTrees[hm[ht[E[x].second]]].update(hd[E[x].second], y);
        }
        if (d == 2) cout << getMax(x - 1, y - 1) << '\n';
    }   

    return 0;
}