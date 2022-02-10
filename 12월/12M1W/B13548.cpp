
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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int sqrtN, N, Q;

struct Query {
    int s, e, idx;
    bool operator < (Query& x) {
        if (s / sqrtN == x.s / sqrtN) return x.e < e;
        return s / sqrtN < x.s / sqrtN;
    }
};

int v[100001];
int cnt[100001], rn[100001], result;
vector<Query> vq;
vector<int> ans;

void oper(int tar, bool plus) {
    if (plus) {
        rn[cnt[tar]]--; cnt[tar]++; rn[cnt[tar]]++;
        result = max(result, cnt[tar]);
    }
    else {
        rn[cnt[tar]]--;
        if (rn[cnt[tar]] == 0 && cnt[tar] == result) result--;
        cnt[tar]--; rn[cnt[tar]]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N, sqrtN = sqrt(N);
    for (int i = 1; i <= N; i++) cin >> v[i];

    cin >> Q;
    vq.resize(Q);
    ans.resize(Q, 0);
    for (int i = 0; i < Q; i++) {
        cin >> vq[i].s >> vq[i].e;
        vq[i].idx = i;
    }
    sort(vq.begin(), vq.end());
    int sidx, eidx;
    sidx = vq[0].s, eidx = vq[0].e, result = 0, rn[0] = 100000;
    for (int i = sidx; i <= eidx; i++) oper(v[i], 1);
    ans[vq[0].idx] = result;

    for (int i = 1; i < Q; i++) {
        while (eidx > vq[i].e) oper(v[eidx--], 0);
        while (eidx < vq[i].e) oper(v[++eidx], 1);
        while (sidx > vq[i].s) oper(v[--sidx], 1);
        while (sidx < vq[i].s) oper(v[sidx++], 0);
        ans[vq[i].idx] = result;
    }

    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';

    return 0;
}