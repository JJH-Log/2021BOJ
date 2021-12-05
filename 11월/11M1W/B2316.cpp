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

vector<int> w[800];
int c[800][800], f[800][800];
int par[800];
int N, P;
int S = 0;
int E = 401;
queue<int> q;

void doFlow() {
    q.push(S);
    while (!q.empty() && par[E] == -1) {
        int now = q.front();
        q.pop();
        for (auto next : w[now]) {
            if (c[now][next] - f[now][next] > 0 && par[next] == -1) {
                q.push(next);
                par[next] = now;
                if (next == E) break;
            }
        }
    }
    while (!q.empty()) q.pop();
}

int networkFlow() {
    int result = 0;
    while (true) {
        fill(par, par + 800, -1);
        doFlow();
        if (par[E] == -1) break;
        int flow = 1e9;
        for (int now = E; now != S; now = par[now]) flow = min(flow, c[par[now]][now] - f[par[now]][now]);
        result += flow;
        for (int now = E; now != S; now = par[now]) {
            f[par[now]][now] += flow;
            f[now][par[now]] -= flow;
        }
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> N >> P;

    for (int i = 0; i < N; i++) {
        w[i].push_back(400 + i);
        w[400 + i].push_back(i);
        c[i][i + 400] = 1;
        if (i == 0 || i == 1) c[i][i + 400] = 1e9;
    }

    for (int i = 0; i < P; i++) {
        cin >> x >> y;
        x--, y--;
        w[400 + x].push_back(y);
        w[y].push_back(400 + x);
        w[400 + y].push_back(x);
        w[x].push_back(400 + y);
        c[400 + x][y] = c[400 + y][x] = 1;
    }
    cout << networkFlow();

    return 0;
}
