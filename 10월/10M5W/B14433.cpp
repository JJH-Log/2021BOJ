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

vector<int> w[2][300];
int p[300], q[300];
bool vtd[300];
int N, M;
int K[2];
int result[2];

bool bipartite(int k, int now) {
    vtd[now] = true;
    for (auto tar : w[k][now]) {
        if (q[tar] == -1 || (!vtd[q[tar]] && bipartite(k, q[tar]))) {
            p[now] = tar;
            q[tar] = now;
            return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K[0] >> K[1];

    int x, y;
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < K[t]; i++) {
            cin >> x >> y;
            x--, y--;
            w[t][x].push_back(y);
        }
        fill(p, p + N, -1);
        fill(q, q + M, -1);
        result[t] = 0;
        for (int i = 0; i < N; i++) {
            fill(vtd, vtd + N, false);
            if (bipartite(t, i)) result[t]++;
        }
    }
    if (result[0] < result[1]) cout << "네 다음 힐딱이";
    else cout << "그만 알아보자";


    return 0;
}
