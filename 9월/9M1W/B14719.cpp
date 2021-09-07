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
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v, l, r;
int H, W;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;
    v.resize(W, 0);
    l.resize(W, 0);
    r.resize(W, 0);
    int i, now;
    int lmax, rmax;
    lmax = rmax = 0;
    for (i = 0; i < W; i++) {
        cin >> v[i];
        now = v[i];
        if (lmax < now) lmax = now;
        l[i] = lmax;
    }
    for (i = W - 1; i >= 0; i--) {
        now = v[i];
        if (rmax < now) rmax = now;
        r[i] = rmax;
    }
    int total = 0;
    for (i = 0; i < W; i++) total +=  min(l[i], r[i]) - v[i];
    cout << total;
    return 0;
}