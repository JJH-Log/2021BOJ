#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 100000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int w[16][16];
int v[1 << 16];
int dp[1 << 16];
int N, M;

int cnt1(int X) {
    int result = 0;
    while (X) {
        if (X % 2) result++;
        X /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i, j, k, state, result;
    string s;
    cin >> N;
    for (i = 0; i < (1 << N); i++) {
        v[i] = cnt1(i);
        for (j = 0; j < N; j++) dp[i] = 1e9;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) cin >> w[i][j];
    }
    cin >> s;
    state = 0; result = 1e9;
    for (i = 0; i < N; i++) if (s[i] == 'Y') state += (1 << i);
    dp[state] = 0;
    cin >> M;
    if (v[state] >= M) result = 0;
    else {
        for (i = 0; i < (1 << N); i++) {
            for (j = 0; j < N; j++) {
                if ((i & (1 << j)) == 0) continue;
                for (k = 0; k < N; k++) {
                    state = i + (1 << k);
                    if ((i & (1 << k)) == 0 && (dp[state] > dp[i] + w[j][k])) {
                        dp[state] = dp[i] + w[j][k];
                        if (v[state] >= M) result = min(result, dp[state]);
                    }
                }
            }
        }
    }
    if (result == 1e9) cout << -1;
    else cout << result;
    return 0;
}