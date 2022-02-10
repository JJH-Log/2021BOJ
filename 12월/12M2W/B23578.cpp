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
#define BOUND 100002
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

vector<int> v;
struct node {
    int idx, cn;
    bool operator<(const node& X) const {
        if ((lld)v[idx] * (2 * cn + 1) == (lld)v[X.idx] * (2 * X.cn + 1)) return cn > X.cn;
        return (lld)v[idx] * (2 * cn + 1) > (lld)v[X.idx] * (2 * X.cn + 1);
    }
};

priority_queue<node> pqn;
int N, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    lld result = 0;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    pqn.push({ 0, 0 });

    for (int i = 1; i < N; i++) {
        node now = pqn.top();
        pqn.pop();
        result += (lld)v[now.idx] * (2 * now.cn + 1);
        result += v[i];
        pqn.push({ now.idx, now.cn + 1 });
        pqn.push({ i, 1 });
    }
    cout << result;

    return 0;
}