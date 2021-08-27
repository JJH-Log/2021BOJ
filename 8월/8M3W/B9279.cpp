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

vector<vector<pair<int,int>>> w;
int N, P;

int dfs(int now, int parent) {
    int result = MAXINT;
    int total = 0;
    for (auto& next : w[now]) {
        if (next.first == parent) result = next.second;
        else total += dfs(next.first, now);
    }
    if (!total) return result;
    else return min(result, total);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i, x, y, d;
    while (true) {
        cin >> N >> P;
        if (cin.eof()) break;
        w.resize(N);
        for (i = 1; i < N; i++) {
            cin >> x >> y >> d;
            x--, y--;
            w[x].push_back({ y, d });
            w[y].push_back({ x, d });
        }
        cout << dfs(P - 1, -1) << '\n';
        w.clear();
    }

    return 0;
}