
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


int N, M;
vector<vector<int>> w;
int dfsn, cnt;
vector<int> dn, fn, rn;
stack<int> s;

int dfs(int now) {
    dn[now] = ++dfsn;
    s.push(now);
    int FLAG = dn[now];
    for (auto tar : w[now]) {
        if (dn[tar] == -1) FLAG = min(FLAG, dfs(tar));
        else if (fn[tar] == -1) FLAG = min(FLAG, dn[tar]);
        if (fn[tar] != -1) rn[fn[tar]]++;
    }
    if (FLAG == dn[now]) {
        ++cnt;
        rn.push_back(0);
        while (true) {
            int tmp = s.top();
            s.pop();
            fn[tmp] = cnt;
            if (tmp == now) break;
        }
    }
    return FLAG;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    dfsn = cnt = 0;
    cin >> N >> M;
    dn.resize(N + 1, -1);
    fn.resize(N + 1, -1);
    w.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        w[x].push_back(y);
    }

    rn.push_back(0);
    for (int i = 1; i <= N; i++) if (dn[i] == -1) dfs(i);

    int result = 0;
    for (int i = 1; i <= cnt; i++) if (!rn[i]) result++;
    cout << result;

    return 0;
}