
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
#include <bitset>
#include <cassert>
#include <sstream>
#define MOD 1000000009
#define BOUND 10000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, Q;
vector<lld> v1, v2, v;

pii solve(int l, int r, int x, int y, int k) {
    int mid = (l + r) / 2;
    int a = upper_bound(v1.begin(), v1.end(), v[mid]) - v1.begin();
    int b = upper_bound(v2.begin(), v2.end(), v[mid]) - v2.begin();
    a = min(a, x), b = min(b, y);
    if (a + b == k) {
        if (v[mid] == v1[a - 1]) return { 1, a };
        if (v[mid] == v2[b - 1]) return { 2, b };
        if (v1[a - 1] > v2[b - 1]) return { 1, a };
        else return { 2, b };
    }
    if (a + b < k) return solve(mid + 1, r, x, y, k);
    else return solve(l, mid - 1, x, y, k);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v1.resize(N, 0);
    v2.resize(N, 0);
    v.resize(2 * N, 0);
    for (int i = 0; i < N; i++) cin >> v1[i], v[i] = v1[i];
    for (int i = 0; i < N; i++) cin >> v2[i], v[i + N] = v2[i];
    sort(v.begin(), v.end());
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        pii ans = solve(0, 2 * N - 1, x, y, k);
        cout << ans.first << ' ' << ans.second << '\n';
    }


    return 0;
}