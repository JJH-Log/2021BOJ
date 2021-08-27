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
#define MOD 1000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> w;
vector<int> v;
vector<bool> vtd;
vector<int> dn;
int N, M, dfsn;
bool result;

void dfs(int now, int parent, bool isRoot) {
    vtd[now] = true;
    dn[now] = ++dfsn;
    if (w[now].size() == 0) return;
    else if (w[now].size() == 1) {
        v[now] = 1;
        if (!vtd[w[now][0]]) dfs(w[now][0], now, false);
    }
    else if (w[now].size() == 2) {
        if (isRoot) {
            dfs(w[now][0], now, false);
            v[now] = v[w[now][0]];
            if (!vtd[w[now][1]]) dfs(w[now][1], now, false);
        }
        else {
            int next;
            if (parent == w[now][0]) next = w[now][1];
            else next = w[now][0];
            if (!vtd[next]) {
                dfs(next, now, false);
                v[now] = v[next];
            }
            else v[now] = 1;
        }
    }
    else if (w[now].size() == 3) {
        int cnt1 = 0;
        int cnt2 = 0;
        int ignore = 0;
        for (auto& next : w[now]) {
            if (next == parent) {
                if (v[parent]) cnt1 += v[parent];
                else ignore++;
            }
            else {
                if (!vtd[next]) {
                    dfs(next, now, false);
                    cnt2 += v[next];
                }
                else {
                    if (dn[next] < dn[now]) cnt1++;
                    else cnt2 = max(cnt2, 2);
                }
            }
        }
        //cout << "NOW : " << now + 1 << ' ' << cnt << ' ' << ignore << endl;
        if (cnt1 + cnt2 + ignore > 3) result = true;
        v[now] = cnt2;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, x, y;

    while (true) {
        cin >> N >> M;
        if (cin.eof()) break;
        w.resize(N);
        v.resize(N, 0);
        vtd.resize(N, false);
        dn.resize(N, 0);
        result = false;
        dfsn = 0;
        for (i = 0; i < M; i++) {
            cin >> x >> y;
            x--, y--;
            w[x].push_back(y);
            w[y].push_back(x);
        }
        for (i = 0; i < N; i++) if (w[i].size() > 3) result = true;
        if (!result) for (i = 0; i < N; i++) if (!vtd[i]) dfs(i, -1, true);
        if (result) cout << "YES\n";
        else cout << "NO\n";

        w.clear();
        v.clear();
        vtd.clear();
        dn.clear();
    }
    return 0;
}