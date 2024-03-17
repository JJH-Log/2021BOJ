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

struct pos {
    lld x, y;
};
vector<pos> v;
vector<pos> w;
stack<pos> s;
stack<pos> s2;
int N;
pos base;

lld ccw(pos A, pos B, pos C) {
    return A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y;
}

lld dist(pos A, pos B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

pos diff(pos A, pos B) {
    return { B.x - A.x, B.y - A.y };
}

bool comPos(pos A, pos B) {
    if (A.x == B.x) return A.y < B.y;
    return A.x < B.x;
}

bool cmpCCW(pos A, pos B) {
    lld result = ccw(base, A, B);
    if (result == 0) return (abs(A.x - base.x) + abs(A.y - base.y)) < (abs(B.x - base.x) + abs(B.y - base.y));
    else return result > 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(8);
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y;
    }
    sort(v.begin(), v.end(), comPos);
    base = v[0];
    sort(v.begin(), v.end(), cmpCCW);

    s.push(v[0]);
    s.push(v[1]);

    for (int i = 2; 2 <= i && i <= N; i++) {
        if (i == N) i = 0;
        while (true) {
            if (s.size() == 1) {
                s.push(v[i]);
                break;
            }
            pos B = s.top();
            s.pop();
            pos A = s.top();
            if ((A.x == v[i].x && A.y == v[i].y) || ccw(A, B, v[i]) > 0) {
                s.push(B);
                s.push(v[i]);
                break;
            }
        }
    }
    s.pop();
    while (!s.empty()) {
        s2.push(s.top());
        s.pop();
    }
    while (!s2.empty()) {
        w.push_back(s2.top());
        s2.pop();
    }

    int move1, move2, idx1, idx2;
    pos A, B, C, D;
    lld result = 0;
    lld ans;
    move1 = move2 = idx1 = idx2 = 0;

    while (move1 != w.size() && move2 != w.size() * 2) {
        A = w[idx1];
        B = w[(idx1 + 1) % w.size()];
        C = w[idx2];
        D = w[(idx2 + 1) % w.size()];
        result = max(result, dist(A, C));
        ans = ccw(A, B, diff(diff(B, C), D));
        if (ans >= 0) idx2 = (idx2 + 1) % w.size(), move2++;
        else idx1 = (idx1 + 1) % w.size(), move1++;
    }

    cout << result;
    return 0;
}
