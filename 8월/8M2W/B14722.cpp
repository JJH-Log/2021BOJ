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

vector<vector<int>> v;
vector<vector<vector<int>>> dp;
int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k, l, dx, dy;
    cin >> N;
    v.resize(N, vector<int>(N, 0));
    dp.resize(3, vector<vector<int>>(N, vector<int>(N, -1e9)));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) cin >> v[i][j];
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (v[i][j] == 0) dp[0][i][j] = max(1, dp[0][i][j]);
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 2; l++) {
                    dx = i + "21"[l] - '1';
                    dy = j + "12"[l] - '1';
                    if (dx < N && dy < N) {
                        if (v[dx][dy] == k) dp[k][dx][dy] = max(dp[k][dx][dy], dp[(k + 2) % 3][i][j] + 1);
                        dp[k][dx][dy] = max(dp[k][dx][dy], dp[k][i][j]);
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 3; i++) result = max(result, dp[i][N - 1][N - 1]);
    cout << result;

    return 0;
}