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
vector<lld> v1, v2, v3, v;

pii solve(int l, int r, int x, int y, int z, int k) {
    int mid = (l + r) / 2;
    int a = upper_bound(v1.begin(), v1.end(), v[mid]) - v1.begin();
    int b = upper_bound(v2.begin(), v2.end(), v[mid]) - v2.begin();
    int c = upper_bound(v3.begin(), v3.end(), v[mid]) - v3.begin();
    a = min(a, x), b = min(b, y); c = min(c, z);
    if (a + b + c == k) {
        if (v[mid] == v1[a - 1]) return { 1, a };
        if (v[mid] == v2[b - 1]) return { 2, b };
        if (v[mid] == v3[c - 1]) return { 3, c };

        if (v1[a - 1] > v2[b - 1] && v1[a - 1] > v3[c - 1]) return { 1, a };
        if (v2[b - 1] > v1[a - 1] && v2[b - 1] > v3[c - 1]) return { 2, b };
        return { 3 , c };
    }
    if (a + b + c < k) return solve(mid + 1, r, x, y, z, k);
    else return solve(l, mid - 1, x, y, z, k);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v1.resize(N, 0);
    v2.resize(N, 0);
    v3.resize(N, 0);
    v.resize(3 * N, 0);
    for (int i = 0; i < N; i++) cin >> v1[i], v[i] = v1[i];
    for (int i = 0; i < N; i++) cin >> v2[i], v[i + N] = v2[i];
    for (int i = 0; i < N; i++) cin >> v3[i], v[i + 2 * N] = v3[i];
    sort(v.begin(), v.end());
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x, y, z, k;
        cin >> x >> y >> z >> k;
        pii ans = solve(0, 3 * N - 1, x, y, z, k);
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}