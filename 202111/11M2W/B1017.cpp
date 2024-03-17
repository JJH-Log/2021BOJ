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

vector<int> v, result;
set<int> s;
vector<int> w[50];
int p[50], q[50];
bool vtd[50];
int lock;

bool isPrime(int X) {
    for (auto t : s) {
        if (t > sqrt(X)) break;
        if (X % t == 0) return false;
    }
    return true;
}


bool bipartite(int now) {
    vtd[now] = true;
    for (auto tar : w[now]) {
        if (tar == 0 || tar == lock) continue;
        if (q[tar] == -1 || (!vtd[q[tar]] && bipartite(q[tar]))) {
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
    
    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    s.insert(2);
    for (int i = 3; i < 2000; i += 2) if (isPrime(i)) s.insert(i);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (s.count(v[i] + v[j])) {
                if (v[i] % 2) w[i].push_back(j);
                else w[j].push_back(i);
            }
        }
    }

    int cnt;
    for (int i = 1; i < N; i++) {
        lock = i, cnt = 0;
        if (!s.count(v[0] + v[i])) continue;
        fill(p, p + N, -1);
        fill(q, q + N, -1);
        for (int j = 1; j < N; j++) {
            if (j == i) continue;
            fill(vtd, vtd + N, false);
            if ((v[j] % 2) && bipartite(j)) cnt++;
        }
        if (cnt + 1 == (N / 2)) result.push_back(v[i]);
    }
    if (!result.size()) cout << -1;
    else {
        sort(result.begin(), result.end());
        for (auto x : result) cout << x << ' ';
    }

    
    return 0;
}
