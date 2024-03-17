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
vector<vector<int>> w; //누적 합
int dp[50][50][50][50];
int N, M;

int getSum(int x1, int y1, int x2, int y2) {
    int a1, a2, a3;
    (x1 && y1) ? a1 = w[x1 - 1][y1 - 1] : a1 = 0;
    x1 ? a2 = w[x1 - 1][y2] : a2 = 0;
    y1 ? a3 = w[x2][y1 - 1] : a3 = 0;
    //cout << "Get Sum of " << x1 << ',' << y1 << ',' << x2 << ',' << y2 << " : " << w[x2][y2] << ' ' << a1 << ' ' << a2 << ' ' << a3 << endl;
    return w[x2][y2] - a2 - a3 + a1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k, l, S;
    cin >> N >> M;
    v.resize(N, vector<int>(M, 0));
    w.resize(N, vector<int>(M, 0));

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> v[i][j];
            dp[i][j][i][j] = 0;
            w[i][j] += v[i][j];
            if (i) w[i][j] += w[i - 1][j];
            if (j) w[i][j] += w[i][j - 1];
            if (i && j) w[i][j] -= w[i - 1][j - 1];
        }
    }

    int dx, dy;
    for (dx = 1; dx < N; dx++) {
        for (i = 0; i + dx < N; i++) {
            for (j = 0; j < M; j++) {
                dp[i][j][i + dx][j] = 2e9;
                for (k = 0; k < dx; k++) dp[i][j][i + dx][j] = min(dp[i][j][i + dx][j], dp[i][j][i + k][j] + dp[i + k + 1][j][i + dx][j]);
                dp[i][j][i + dx][j] += getSum(i, j, i + dx, j);
            }
        }
    }

    for (dy = 1; dy < M; dy++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j + dy < M; j++) {
                dp[i][j][i][j + dy] = 2e9;
                for (k = 0; k < dy; k++) dp[i][j][i][j + dy] = min(dp[i][j][i][j + dy], dp[i][j][i][j + k] + dp[i][j + k + 1][i][j + dy]);
                dp[i][j][i][j + dy] += getSum(i, j, i, j + dy);
            }
        }
    }

    for (dx = 1; dx < N; dx++) {
        for (dy = 1; dy < M; dy++) {
            for (i = 0; i + dx < N; i++) {
                for (j = 0; j + dy < M; j++) {
                    dp[i][j][i + dx][j + dy] = 2e9;
                    for (k = 0; k < dx; k++) dp[i][j][i + dx][j + dy] = min(dp[i][j][i + dx][j + dy], dp[i][j][i + k][j + dy] + dp[i + k + 1][j][i + dx][j + dy]);
                    //cout << "Min of [X] " << i << ',' << j << ',' << i + dx << ',' << j + dy << " : " << dp[i][j][i + dx][j + dy] << endl;
                    for (k = 0; k < dy; k++) dp[i][j][i + dx][j + dy] = min(dp[i][j][i + dx][j + dy], dp[i][j][i + dx][j + k] + dp[i][j + k + 1][i + dx][j + dy]);
                    //cout << "Min of [Y]" << i << ',' << j << ',' << i + dx << ',' << j + dy << " : " << dp[i][j][i + dx][j + dy] << endl;
                    dp[i][j][i + dx][j + dy] += getSum(i, j, i + dx, j + dy);
                    //cout << "Result of " << i << ',' << j << ',' << i + dx << ',' << j + dy << " : " << dp[i][j][i + dx][j + dy] << endl;
                }
            }
        }
    }
    cout << dp[0][0][N - 1][M - 1];

    return 0;
}