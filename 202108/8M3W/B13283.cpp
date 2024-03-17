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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct pos {
    int x, y, r;
};

vector<int> v;
vector<vector<int>> dp;
vector<vector<bool>> vtd;
queue<pos> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, j, k, N;
    int result;

    while (true) {
        result = 0;
        cin >> N;
        if (!N) break;
        v.resize(N, 0);
        dp.resize(N, vector<int>(N, 0));
        vtd.resize(N, vector<bool>(N, false));
        for (i = 0; i < N; i++) cin >> v[i];
        for (j = 1; j < N; j ++) {
            for (i = 0; i + j < N; i++) {
                if (j == 1) {
                    if (abs(v[i] - v[i + j]) < 2) dp[i][i + j] = 2;
                }
                else {
                    if (dp[i + 1][i + j - 1] == j - 1 && abs(v[i] - v[i + j]) < 2) dp[i][i + j] = j + 1;
                    else for (k = 0; k < j; k ++) dp[i][i + j] = max(dp[i][i + j], dp[i][i + k] + dp[i + k + 1][i + j]);
                }
            }
        }
        cout << dp[0][N - 1] << '\n';

        v.clear();
        dp.clear();
        vtd.clear();
    }

    return 0;
}