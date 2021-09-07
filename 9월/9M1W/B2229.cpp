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
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
    int m, M, val;
};

vector<int> v;
vector<vector<info>> dp; //최솟값, 최댓값
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k;
    cin >> N;
    v.resize(N, 0);
    dp.resize(N, vector<info>(N, { 0, 0, 0 }));
    for (i = 0; i < N; i++) {
        cin >> v[i];
        dp[i][i] = { v[i], v[i], 0 };
    }
    for (j = 1; j < N; j++) {
        for (i = 0; i + j < N; i++) {
            dp[i][i + j] = { min(dp[i][i + j - 1].m, v[i + j]), max(dp[i][i + j - 1].M, v[i + j]), 0 };
            dp[i][i + j].val = dp[i][i + j].M - dp[i][i + j].m;
            for (k = 1; k < j; k++) dp[i][i + j].val = max(dp[i][i + j].val, dp[i][i + k].val + dp[i + k + 1][i + j].val);
        }
    }
    cout << dp[0][N - 1].val;

    return 0;
}