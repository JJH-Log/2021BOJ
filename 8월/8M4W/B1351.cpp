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

map<lld, lld> m;
lld N, P, Q;

lld ans(lld X) {
    if (m.count(X)) return m[X];
    m[X] = ans(X / P) + ans(X / Q);
    return m[X];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    m[0] = 1;
    cin >> N >> P >> Q;
    cout << ans(N);
    return 0;
}