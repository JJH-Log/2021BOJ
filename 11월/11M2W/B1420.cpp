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

vector<int> w[20000];
map<pair<int, int>, int> c, f;
char v[100][100];
int par[20000];
int S, E;
int Si, Sj, Ei, Ej;

void doFlow() {
    fill(par, par + 20000, -1);
    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto next : w[now]) {
            if (par[next] == -1 && c[{now, next}] - f[{now, next}] > 0) {
                par[next] = now;
                q.push(next); 
            }
        }
    }
}

int networkFlow() {
    int result = 0;
    while (true) {
        doFlow();
        if (par[E] == -1) break;
        int flow = 1e9;
        for (int now = E; now != S; now = par[now]) {
            f[{par[now], now}]++;
            f[{now, par[now]}]--;
        }
        result++;
    }
    return result;
}

void addEdge(int s, int e, int x) {
    w[s].push_back(e); c[{s, e}] = x;
    w[e].push_back(s); c[{e, s}] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    int N, M, now, next;
    cin >> N >> M;
    now = 0;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            v[i][j] = s[j];
            if (v[i][j] == 'K') {
                S = now + 1;
                Si = i, Sj = j;
            }
            if (v[i][j] == 'H') {
                E = now;
                Ei = i, Ej = j;
            }
            now += 2;
        }
    }
    
    if (abs(Si - Ei) + abs(Sj - Ej) == 1) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < N * M; i++) addEdge(2 * i, 2 * i + 1, 1);
    now = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] != '#') {
                if (i + 1 < N && v[i + 1][j] != '#') {
                    next = now + 2 * M;
                    addEdge(now + 1, next, 1e9);
                    addEdge(next + 1, now, 1e9);
                }
                if (j + 1 < M && v[i][j + 1] != '#') {
                    next = now + 2;
                    addEdge(now + 1, next, 1e9);
                    addEdge(next + 1, now, 1e9);
                }
            }
            now += 2;
        }
    }

    cout << networkFlow();
    return 0;
}
