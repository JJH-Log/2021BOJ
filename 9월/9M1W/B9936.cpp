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

vector<vector<lld>> v;
vector<vector<lld>> dp;
vector<vector<lld>> nxt;
int N, K;


int getNum(int x, int idx, bool isVertical) {
    if (isVertical) return v[x][idx] + v[x - 1][idx];
    return v[x][idx] + v[x][idx + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, k, st;
    lld total = 0;
    cin >> N >> K;
    dp.resize(K + 1, vector<lld>((1 << 6), MININT));
    
    v.resize(N, vector<lld>(3, 0));
    for (i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        total += v[i][0] + v[i][1] + v[i][2];
    }
    dp[0][0] = 0; dp[1][3] = getNum(0, 0, false); dp[1][6] = getNum(0, 1, false);
    for (i = 1; i < N; i++) {
        for (k = 0; k < K; k++) {
            for (st = 0; st < 64; st++) {
                if (dp[k][st] != MININT) {
                    if ((st & 9) == 0) dp[k + 1][st + 9] = max(dp[k + 1][st + 9], dp[k][st] + getNum(i, 0, true));
                    if ((st & 18) == 0) dp[k + 1][st + 18] = max(dp[k + 1][st + 18], dp[k][st] + getNum(i, 1, true));
                    if ((st & 36) == 0) dp[k + 1][st + 36] = max(dp[k + 1][st + 36], dp[k][st] + getNum(i, 2, true));
                    if ((st & 24) == 0) dp[k + 1][st + 24] = max(dp[k + 1][st + 24], dp[k][st] + getNum(i, 0, false));
                    if ((st & 48) == 0) dp[k + 1][st + 48] = max(dp[k + 1][st + 48], dp[k][st] + getNum(i, 1, false));
                }
            }
        }
        nxt.resize(K + 1, vector<lld>((1 << 6), MININT));
        for (k = 0; k <= K; k++) {
            for (st = 0; st < 64; st++) {
                nxt[k][(st >> 3)] = max(nxt[k][(st >> 3)], dp[k][st]);
            }
        }
        dp = nxt;
        nxt.clear();
    }
    lld result = MININT;
    for (st = 0; st < 8; st++) result = max(result, dp[K][st]);
    cout << result;
    return 0;
}