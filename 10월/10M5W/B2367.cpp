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


int c[302][302], f[302][302];
vector<int> w[302];
int par[302];
int N, K, D;
queue<int> q;
int S = 300;
int E = 301;

void doFlow() {
    fill(par, par + 302, -1);
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

int flow() {
    int result = 0;
    while (true) {
        doFlow();
        if (par[E] == -1) break;
        int ff = 1e9;
        for (int now = E; now != S; now = par[now]) ff = min(ff, c[par[now]][now] - f[par[now]][now]);
        result += ff;
        for (int now = E; now != S; now = par[now]) {
            f[par[now]][now] += ff;
            f[now][par[now]] -= ff;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, p;
    cin >> N >> K >> D;

    for (int i = 0; i < D; i++) {
        cin >> t;
        c[200 + i][E] = t;
        w[200 + i].push_back(E);
        w[E].push_back(200 + i);
    }
    for (int i = 0; i < N; i++) {
        cin >> t;
        for (int j = 0; j < t; j++) {
            cin >> p;
            c[i][200 + p - 1] = 1;
            w[i].push_back(200 + p - 1);
            w[200 + p - 1].push_back(i);
        }
        c[S][i] = K;
        w[S].push_back(i);
        w[i].push_back(S);
    }

    cout << flow();

    return 0;
}
