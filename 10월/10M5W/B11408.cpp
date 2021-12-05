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

vector<int> w[802];
int c[802][802], d[802][802], f[802][802];
int N, M;
int par[802], dst[802];
bool inQ[802];
queue<int> q;
int S = 800;
int E = 801;


void doFlow() {
    fill(par, par + 802, -1);
    fill(dst, dst + 802, 1e9);
    fill(inQ, inQ + 802, false);

    dst[S] = 0;
    inQ[S] = true;
    q.push(S);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        inQ[now] = false;
        for (auto next : w[now]) {
            if (next == par[now]) continue;
            if (c[now][next] - f[now][next] > 0 && dst[next] > dst[now] + d[now][next]) {
                par[next] = now;
                dst[next] = dst[now] + d[now][next];
                if (!inQ[next]) {
                    inQ[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

pair<int, int> networkFlow() {
    int work, cost;
    work = cost = 0;
    while (true) {
        doFlow();
        if (par[E] == -1) break;
        int flow = 1e9;
        for (int now = E; now != S; now = par[now]) flow = min(flow, c[par[now]][now] - f[par[now]][now]);
        for (int now = E; now != S; now = par[now]) {
            cost += flow * d[par[now]][now];
            f[par[now]][now] += flow;
            f[now][par[now]] -= flow; //역방향 flow 도 흘려주기
        }
        work += flow;
    }
    return { work, cost };
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        w[S].push_back(i);
        w[i].push_back(S);
        c[S][i] = 1;
    }
    for (int i = 400; i < 400 + M; i++) {
        w[i].push_back(E);
        w[E].push_back(i);
        c[i][E] = 1;
    }
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int x, y;
            cin >> x >> y;
            w[i].push_back(400 + x - 1);
            w[400 + x - 1].push_back(i);
            c[i][400 + x - 1] = 1e9;
            d[i][400 + x - 1] = y;
            d[400 + x - 1][i] = -y;
        }
    }
    pair<int, int> result = networkFlow();
    cout << result.first << '\n' << result.second;
    return 0;
}
