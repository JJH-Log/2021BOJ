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
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int N, Q;
vector<lld> v, sv;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int x, y;
    cin >> N >> Q;
    v.resize(N + 1, 0);
    sv.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> x;
        v[i] = v[i - 1] + x;
        sv[i] = sv[i - 1] + (lld)x * x;
    }
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        cout << (v[y] * v[y] - 2 * v[x - 1] * v[y] + v[x - 1] * v[x - 1] - sv[y] + sv[x - 1]) / 2 << '\n';
    }

    return 0;
}
