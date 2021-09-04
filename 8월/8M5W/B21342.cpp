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

struct drone {
    lld x, v;
    int l, r;
    bool used;
};

struct adjInfo {
    lld dx, dv;
    int l, r;
};

struct cmp {
    bool operator()(adjInfo& A, adjInfo& B) {
        return A.dx * B.dv > B.dx * A.dv;
    }
};

priority_queue<adjInfo, vector<adjInfo>, cmp> pq;
drone v[100002];
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, x, vx;
    lld dx, dv;
    cin >> N;
    v[0] = { (lld)-2e9, (lld)-2e9, 0, 1, 0 };
    v[N + 1] = { (lld)2e9, (lld)2e9, N, N + 1, 0 };

    for (i = 1; i <= N; i++) {
        cin >> x >> vx;
        v[i] = { x, vx, i - 1, i + 1, false };
        dx = v[i].x - v[i - 1].x;
        dv = v[i - 1].v - v[i].v;
        if (dv > 0) pq.push({ dx, dv, i - 1, i });
    }

    adjInfo now;
    while (!pq.empty()) {
        now = pq.top();
        pq.pop();
        if (v[now.l].used || v[now.r].used) continue;
        else {
            v[now.l].used = true;
            v[now.r].used = true;
            v[v[now.l].l].r = v[now.r].r;
            v[v[now.r].r].l = v[now.l].l;
            dx = v[v[now.r].r].x - v[v[now.l].l].x;
            dv = v[v[now.l].l].v - v[v[now.r].r].v;
            if (dv > 0) pq.push({ dx, dv, v[now.l].l, v[now.r].r });
        }
    }
    vector<int> result;
    for (i = 1; i <= N; i++) if (!v[i].used) result.push_back(i);
    cout << result.size() << '\n';
    for (i = 0; i < result.size(); i++) cout << result[i] << ' ';
    return 0;
}