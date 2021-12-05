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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
    int num;
    int depth;
    lld cost;
};

vector<vector<pair<int, int>>> w;
int N, T;

info dfs(int now, int parent, int d) {
    info result = { now, d, 0 };
    for (auto next : w[now]) {
        if (next.first == parent) continue;
        info ans = dfs(next.first, now, d + 1);
        ans.cost += next.second;
        if (ans.depth > result.depth || ((ans.depth == result.depth) && (ans.cost < result.cost))) result = ans;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> N >> T;
    w.resize(N);
    for (int i = 1; i < N; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        x--, y--;
        w[x].push_back({ y, d });
        w[y].push_back({ x, d });
    }
    int root = dfs(0, -1, 0).num;
    lld result = dfs(root, -1, 0).cost;

    cout << (result + T - 1) / T;

    


    return 0;
}
