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
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 5000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<int> w[10001];
int K, N;
int dn[10001];
int df[10001];
int gtf[10001];
int res[10001];
int dfsn;
vector<vector<int>> g;
stack<int> st;

int rev(int X) {
    if (X >= K) return X -= K;
    return X += K;
}

void connect(int A, int B) {
    w[rev(A)].push_back(B);
    w[rev(B)].push_back(A);
}

int scc(int now) {
    dn[now] = ++dfsn;
    st.push(now);
    int FLAG = dn[now];
    for (auto tar : w[now]) {
        if (df[tar]) continue;
        if (!dn[tar]) FLAG = min(FLAG, scc(tar));
        else FLAG = min(FLAG, dn[tar]);
    }
    if (FLAG == dn[now]) {
        vector<int> tg;
        int gi = g.size();
        while (true) {
            int t = st.top();
            st.pop();
            tg.push_back(t);
            df[t] = gi;
            if (t == now) break;
        }
        g.push_back(tg);
    }
    return FLAG;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    char c;

    cin >> K >> N;
    for (int i = 0; i < N; i++) {
        int tmp[3];
        for (int j = 0; j < 3; j++) {
            cin >> tmp[j] >> c; tmp[j]--;
            if (c == 'B') tmp[j] = rev(tmp[j]);
        }
        for (int j = 0; j < 3; j++) connect(tmp[j], tmp[(j + 1) % 3]);
    }
    g.push_back(vector<int>());

    for (int i = 0; i < 2 * K; i++) if (!dn[i]) scc(i);

    for (int i = 0; i < K; i++) {
        if (df[i] == df[i + K]) {
            cout << -1;
            return 0;
        }
    }
    memset(gtf, -1, sizeof gtf);
    memset(res, -1, sizeof res);
    for (int i = g.size() - 1; i; i--) {
        if (gtf[i] == -1) gtf[i] = 0;
        for (auto tar : g[i]) {
            res[tar] = gtf[i];
            if (gtf[df[rev(tar)]] == -1) gtf[df[rev(tar)]] = gtf[i] ^ 1;
        }
    }

    for (int i = 0; i < K; i++) cout << (res[i] ? 'R' : 'B');

    return 0;
}