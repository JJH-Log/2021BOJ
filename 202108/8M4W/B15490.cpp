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
#define MOD 10007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;
vector<int> w;
int dp[2][3001][3001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i, j, k, N, temp;
    int state, rival;

    cin >> N;
    v.resize(N, 0);
    w.resize(N, 0);
    for (i = 0; i < N; i++) {
        cin >> temp;
        v[i] = (temp % 2);
        if (i == 0) w[i] = v[i];
        else w[i] = (v[i] + w[i - 1]) % 2;
    }
    for (i = 0; i < N; i++) {
        if (v[i]) dp[0][i][i] = 0, dp[1][i][i] = 1;
        else dp[0][i][i] = 1, dp[1][i][i] = 0;
    }
    for (i = 0; i + 1 < N; i++) {
        if (v[i] + v[i + 1]) dp[0][i][i + 1] = 1, dp[1][i][i + 1] = 1;
        else dp[0][i][i + 1] = 1, dp[1][i][i + 1] = 0;
    }
    int result = 0;
    for (j = 2; j < N; j++) {
        state = w[j];
        for (i = 0; i + j < N; i++) {
            if (i) state = (state + 2 + v[i + j] - v[i - 1]) % 2;
            rival = state ^ 1; result = 0;
            result = dp[rival][i + 1][i + j] + dp[rival][i + 2][i + j] + dp[rival][i][i + j - 1] + dp[rival][i][i + j - 2];
            if (result != 4) dp[0][i][i + j] = 1;
            else dp[0][i][i + j] = 0;

            rival = state; result = 0;
            result = dp[rival][i + 1][i + j] + dp[rival][i + 2][i + j] + dp[rival][i][i + j - 1] + dp[rival][i][i + j - 2];
            if (result != 4) dp[1][i][i + j] = 1;
            else dp[1][i][i + j] = 0;
            //cout << "ans for " << i << "to " << i + j << " : " << dp[0][i][i + j] << ' ' << dp[1][i][i + j] << endl;
        }
    }
    if (dp[0][0][N - 1]) cout << "Yes";
    else cout << "No";
    
    return 0;
}