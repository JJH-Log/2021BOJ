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

vector<int> bp;
vector<int> bq;
vector<vector<int>> w;
vector<bool> vtd;

bool binMatch(int now) {
    vtd[now] = true;
    for (auto& next : w[now]) {
        if (bq[next] == -1 || !vtd[bq[next]] && binMatch(bq[next])) {
            bq[next] = now;
            bp[now] = next;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, x, y, N, M;
    cin >> N >> M;
    bp.resize(N, -1);
    bq.resize(N, -1);
    w.resize(N);
    for (i = 0; i < M; i++) {
        cin >> x >> y;
        x--, y--;
        w[x].push_back(y);
    }
    int result = 0;
    for (i = 0; i < N; i++) {
        vtd.resize(N, false);
        if (binMatch(i)) result++;
        vtd.clear();
    }
    cout << result;
    return 0;
}