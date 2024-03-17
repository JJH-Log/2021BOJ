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

vector<vector<int>> w;
vector<int> r, v;
int N;

void dfs(int now, int parent) {
    if (parent != -1) v[now] = (v[now] + 1) % 12;
    for (auto& next : w[now]) {
        if (next == parent) continue;
        dfs(next, now);
        v[now] = (v[now] + 1 + (12 - v[next])) % 12;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, x, y;
    cin >> N;
    w.resize(N);
    r.resize(N);
    for (i = 0; i < N; i++) cin >> r[i];
    for (i = 1; i < N; i++) {
        cin >> x >> y;
        x--, y--;
        w[x].push_back(y);
        w[y].push_back(x);
    }
    int result = 0;
    for (i = 0; i < N; i++) {
        v = r;
        dfs(i, -1);
        if (v[i] == 0 || v[i] == 1) result++;
    }
    cout << result;

    return 0;
}