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

vector<int> v;
vector<int> w;
vector<vector<int>> dp;
int N, K, result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, S;
    cin >> N;
    v.resize(N, 0);
    for (i = 0; i < N; i++) cin >> v[i];
    cin >> K;
    S = 0;
    for (i = 0; i < K; i++) S += v[i];
    for (i = K; i < N; i++) {
        w.push_back(S);
        S += v[i] - v[i - K];
    }
    w.push_back(S);

    dp.resize(2, vector<int>(w.size(), 0));

    for (i = 0; i + K< w.size(); i++) dp[0][i + K] = w[i];
    for (i = 1; i < w.size(); i++) dp[0][i] = max(dp[0][i], dp[0][i - 1]);
    for (i = 0; i + K < w.size(); i++) dp[1][i + K] = dp[0][i] + w[i];
    for (i = 1; i < w.size(); i++) dp[1][i] = max(dp[1][i], dp[1][i - 1]);
    for (i = 0; i < w.size(); i++) result = max(result, dp[1][i] + w[i]);

    cout << result;
    return 0;
}