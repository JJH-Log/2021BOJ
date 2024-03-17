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

int w1[200], w2[200];
bool vtd[200];
int p[200], q[200];
vector<int> w[200];


bool biPartite(int now) {
    vtd[now] = true;
    for (auto next : w[now]) {
        if (q[next] == -1 || (!vtd[q[next]] && biPartite(q[next]))) {
            p[now] = next;
            q[next] = now;
            return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) cin >> w1[i];
    for (int i = 0; i < M; i++) cin >> w2[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((w1[i] <= 2 * w2[j] && 4 * w2[j] <= 3 * w1[i]) || (w1[i] <= w2[j] && 4 * w2[j] <= 5 * w1[i])) w[i].push_back(j);
        }
    }

    int result = 0;
    fill(p, p + 200, -1);
    fill(q, q + 200, -1);
    for (int i = 0; i < N; i++) {
        fill(vtd, vtd + 200, false);
        if (biPartite(i)) result++;
    }
    cout << result;
    return 0;
}
