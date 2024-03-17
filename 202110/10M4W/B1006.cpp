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

vector<vector<int>> v;
vector<vector<int>> dp;
int N, W, T;


void simulation() {
    for (int i = 0; i <= N; i++) {
        if (i > 1) {
            if (v[1][i - 2] + v[1][i - 1] <= W) dp[i][2] = min(dp[i][2], dp[i][0] + 1);
            if (v[0][i - 2] + v[0][i - 1] <= W) dp[i][2] = min(dp[i][2], dp[i][4] + 1);
        }
        dp[i][1] = min(dp[i][1], dp[i][0] + 1);
        dp[i][3] = min(dp[i][3], dp[i][4] + 1);
        if (i > 0 && i < N) {
            if (v[1][i - 1] + v[1][i] <= W) dp[i + 1][3] = min(dp[i + 1][3], dp[i][1] + 1);
            if (v[0][i - 1] + v[0][i] <= W) dp[i + 1][1] = min(dp[i + 1][1], dp[i][3] + 1);
        }
        dp[i][2] = min(dp[i][2], dp[i][1] + 1);
        dp[i][2] = min(dp[i][2], dp[i][3] + 1);
        if (i < N) {
            if (v[0][i] + v[1][i] <= W) dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + 1);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1);
            dp[i + 1][3] = min(dp[i + 1][3], dp[i][2] + 1);
        }
        if (i + 1 < N) {
            if (v[0][i] + v[0][i + 1] <= W) dp[i + 2][0] = min(dp[i + 2][0], dp[i][2] + 1);
            if (v[1][i] + v[1][i + 1] <= W) dp[i + 2][4] = min(dp[i + 2][4], dp[i][2] + 1);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> W;

        int result = 1e9;
        v.resize(2, vector<int>(N, 0));
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) cin >> v[i][j];
        }

        if (N == 1) {
            if (v[0][0] + v[1][0] <= W) cout << 1 << '\n';
            else cout << 2 << '\n';
            continue;
        }

        dp.resize(N + 1, vector<int>(5, 1e9));
        dp[0][2] = 0;
        simulation();
        result = min(result, dp[N][2]);
        dp.clear();

        if (v[0][0] + v[0][N - 1] <= W) {
            dp.resize(N + 1, vector<int>(5, 1e9));
            dp[1][1] = 1;
            simulation();
            result = min(result, dp[N][3]);
            dp.clear();
        }

        if (v[1][0] + v[1][N - 1] <= W) {
            dp.resize(N + 1, vector<int>(5, 1e9));
            dp[1][3] = 1;
            simulation();
            result = min(result, dp[N][1]);
            dp.clear();
        }

        if (v[0][0] + v[0][N - 1] <= W && v[1][0] + v[1][N - 1] <= W) {
            dp.resize(N + 1, vector<int>(5, 1e9));
            dp[1][2] = 2;
            simulation();
            result = min(result, dp[N - 1][2]);
            dp.clear();
        }

        cout << result << '\n';
        v.clear();
    }
    return 0;
}
