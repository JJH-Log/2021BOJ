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
#define MOD 1000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct pos {
    lld x, y;
    int idx;
};

bool cmpPos(pos A, pos B) {
    if (A.x == B.x) return A.y < B.y;
    return A.x < B.x;
}

bool cmpIdx(pos A, pos B) {
    return A.idx < B.idx;
}

pos minIdx(pos A, pos B) {
    if (A.idx > B.idx) return B;
    return A;
}

lld abs_ccw(pos A, pos B, pos C, pos D) {
    lld dx1, dx2, dy1, dy2;
    dx1 = abs(B.x - A.x); dy1 = abs(B.y - A.y);
    dx2 = abs(D.x - C.x); dy2 = abs(D.y - C.y);
    return dx1 * dy2 - dy1 * dx2;
}

vector<pos> v, w;
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, x, y;
    lld ans;
    pos A, B;
    pair<pos, pos> now;

    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back({ x, y, i + 1 });
    }

    sort(v.begin(), v.end(), cmpPos);
    now = { v[0], v[1] };
    A = minIdx(v[0], v[1]);
    for (i = 2; i < N; i++) {
        ans = abs_ccw(now.first, now.second, v[i - 1], v[i]);
        if (ans > 0) {
            now = { v[i - 1],v[i] };
            A = minIdx(v[i - 1], v[i]);
        }
        else if (ans == 0) {
            A = minIdx(A, v[i - 1]);
            A = minIdx(A, v[i]);
        }
    }

    sort(v.begin(), v.end(), cmpIdx);
    if (A.idx != 1) B = v[0];
    else B = v[1];
    for (i = 0; i < N; i++) {
        if (v[i].idx == A.idx || v[i].idx == B.idx) continue;
        if (abs_ccw(A, B, A, v[i]) > 0) B = v[i];
    }
    cout << A.idx << ' ' << B.idx;
    return 0;
}