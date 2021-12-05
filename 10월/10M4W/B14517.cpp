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
#define MOD 10007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int N;
    string s;
    cin >> s;
    N = s.size();

    if (N == 1) {
        cout << 1;
        return 0;
    }

    v.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) v[i][i] = 1;
    for (int j = 1; j < N; j++) {
        for (int i = 0; i + j < N; i++) {
            if (s[i] == s[i + j]) v[i][i + j] = (v[i][i + j - 1] + v[i + 1][i + j] + 1) % MOD;
            else v[i][i + j] = (v[i][i + j - 1] + v[i + 1][i + j] - v[i + 1][i + j - 1] + MOD) % MOD;
        }
    }
    cout << v[0][N - 1];

    return 0;
}
