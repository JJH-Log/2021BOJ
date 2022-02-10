
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
#define BOUND 100002
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct tile {
    int a, b;
    bool ef, ee, of, oe;
};

int N;
tile t[250000];
int par[250000];
vector<vector<int>> w;

void connect(int X, int Y) {
    w[X].push_back(Y);
    w[Y].push_back(X);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int bound = N * N - N / 2;
    w.resize(bound + 1);
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        for (int j = (i % 2); j < 2 * N - (i % 2); j+=2, cnt++) {
            cin >> t[cnt].a >> t[cnt].b;
            if (j == 0) t[cnt].ef = true;
            if (j == 1) t[cnt].of = true;
            if (j == 2 * N - 2) t[cnt].ee = true;
            if (j == 2 * N - 3) t[cnt].oe = true;
        }
    }

    for (int i = 1; i <= N * N - (N / 2); i++) {
        if (!t[i].ef) {
            if (i + N - 1 <= bound && t[i + N - 1].b == t[i].a) connect(i, i + N - 1);
            if (i - N >= 1 && t[i - N].b == t[i].a) connect(i, i - N);
            if (!t[i].of && t[i - 1].b == t[i].a) connect(i, i - 1);
        }
        if (!t[i].ee) {
            if (i + N <= bound && t[i + N].a == t[i].b) connect(i, i + N);
            if (i - (N - 1) >= 1 && t[i - (N - 1)].a == t[i].b) connect(i, i - (N - 1));
            if (!t[i].oe && t[i + 1].a == t[i].b) connect(i, i + 1);
        }
    }

    int mx = 0;
    queue<int> q;
    q.push(1);
    par[1] = -1;
    
    while (!q.empty()) {
        int now = q.front();
        if (now > mx) mx = now;
        q.pop();
        for (auto tar : w[now]) {
            if (!par[tar]) {
                par[tar] = now;
                q.push(tar);
            }
        }
    }
    stack<int> s;
    for (int i = mx;; i = par[i]) {
        s.push(i);
        if (par[i] == -1) break;
    }
    cout << s.size() << '\n';
    while (!s.empty()) cout << s.top() << ' ', s.pop();

    return 0;
}