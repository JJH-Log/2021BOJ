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

struct pos {
    int x, y, q, t; //q: quadrant, x >= 0 이면 1, x < 0 이면 2
};

lld ccw(pos A, pos B, pos C) {
    return (lld)A.x * B.y + B.x * C.y + C.x * A.y - (A.y * B.x + B.y * C.x + C.y * A.x);
}

bool compare(pos A, pos B) {
    if (A.q == B.q) {
        lld c = ccw({ 0,0,0,0 }, A, B);
        if (c == 0) return abs(A.x) + abs(A.y) < abs(B.x) + abs(B.y);
        else return c < 0;
    }
    else return A.q < B.q;
}

vector<pos> v;
vector<vector<int>> w;
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, N, idx, cnt;
    pos tv, before;
    cin >> tv.x >> tv.y >> N;
    v.resize(N);
    for (i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y >> v[i].t;
        v[i].x -= tv.x, v[i].y -= tv.y;
        if (v[i].x < 0 || (v[i].x == 0 && v[i].y < 0)) v[i].q = 2;
        else v[i].q = 1;
    }
    sort(v.begin(), v.end(), compare);
    cnt = 0;
    for (i = 0; i < N; i++) {
        if (!i) w.push_back(vector<int>());
        else if (before.q != v[i].q || ccw({ 0,0,0,0 }, before, v[i])){
            w.push_back(vector<int>()), cnt++;
        }
        w[cnt].push_back(v[i].t);
        before = v[i];
    }
    int result = 0;
    for (i = 0; i <= cnt; i++) {
        lis.push_back(-1);
        for (j = 0; j < w[i].size(); j++) {
            idx = lower_bound(lis.begin(), lis.end(), w[i][j]) - lis.begin();
            if (idx == lis.size()) lis.push_back(w[i][j]);
            else lis[idx] = w[i][j];
        }
        result += lis.size() - 1;
        lis.clear();
    }
    cout << result;
    return 0;
}