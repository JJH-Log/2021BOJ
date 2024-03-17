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

lld dp[100][21] = { 0, };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, i, j, temp;
    cin >> N;
    cin >> temp;
    dp[0][temp] = 1;
    for (i = 1; i < N - 1; i++) {
        cin >> temp;
        for (j = 0; j + temp < 21; j++) dp[i][j + temp] += dp[i - 1][j];
        for (j = 20; j - temp >= 0; j--) dp[i][j - temp] += dp[i - 1][j];
    }
    cin >> temp;
    cout << (lld)dp[N - 2][temp];

    return 0;
}