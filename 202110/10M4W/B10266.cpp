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



vector<int> v1, v2;
vector<int> c, f; //for clock, fail

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i, j, N;
    cin >> N;
    
    v1.resize(2 * N);
    v2.resize(N);
    f.resize(N);

    c.resize(N);
    for (i = 0; i < N; i++) cin >> c[i];
    sort(c.begin(), c.end());
    c.push_back(c[0] + 360000);
    for (i = 0; i < N; i++) v1[i] = v1[i + N] = c[i + 1] - c[i];
    c.clear();

    c.resize(N);
    for (i = 0; i < N; i++) cin >> c[i];
    sort(c.begin(), c.end());
    c.push_back(c[0] + 360000);
    for (i = 0; i < N; i++) v2[i] = c[i + 1] - c[i];
    c.clear();

    for (i = 1, j = 0; i < N; i++) {
        while (j && v2[j] != v2[i]) j = f[j - 1];
        if (v2[j] == v2[i]) f[i] = ++j;
    }
    bool result = false;
    for (i = 0, j = 0; i < 2 * N; i++) {
        while (j && v2[j] != v1[i]) j = f[j - 1];
        if (v2[j] == v1[i]) j++;
        if (j == N) {
            result = true;
            break;
        }
    }

    if (result) cout << "possible";
    else cout << "impossible";

    return 0;
}
