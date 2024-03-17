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
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


vector<int> pre;
vector<string> v;
vector<vector<lld>> dp;
vector<vector<int>> modTable;
vector<int> dplens;
int N, K;

int getLen(int X) {
    int result = 0;
    while (X) {
        X /= 10;
        result++;
    }
    return result;
}

void fillpre(int sz) {
    int now = 1;
    for (int i = 1; i < sz; i++) {
        now = (now * 10) % K;
        pre[i] = now;
    }
}


void fillmodTable(int idx, int lens) {
    string num = v[idx];
    int now = 0;
    for (int i = 0; i < num.size(); i++) now += (int)(num[num.size() - 1 - i] - '0') * pre[lens + i];
    modTable[idx][lens] = now % K;
}

lld gcd(lld X, lld Y) {
    if (X < Y) return gcd(Y, X);
    if (!Y) return X;
    return gcd(Y, X % Y);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    cin >> K;

    pre.resize(50 * N + 1, 1);
    fillpre(50 * N + 1);

    modTable.resize(N, vector<int>(50 * N + 1, -1));

    dplens.resize(1 << N, 0);
    dp.resize(1 << N, vector<lld>(K, 0));
    dp[0][0] = 1;
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if (!(i & (1 << j))) {
                for (int k = 0; k < K; k++) {
                    if (modTable[j][dplens[i]] == -1) fillmodTable(j, dplens[i]);
                    dp[i | (1 << j)][(k + modTable[j][dplens[i]]) % K] += dp[i][k];
                    dplens[i | (1 << j)] = dplens[i] + v[j].size();
                }
            }
        }
    }

    lld total = 0;
    for (int i = 0; i < K; i++) total += dp[(1 << N) - 1][i];
    lld gcds = gcd(total, dp[(1 << N) - 1][0]);
    cout << dp[(1 << N) - 1][0] / gcds << '/' << total / gcds;

    return 0;
}
