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
    int x, y;
};

struct info {
    int a, b;
    double dist;
    info(int A, int B, pos p1, pos p2) :a(A), b(B) {
        dist = sqrt(((lld)p1.x - p2.x) * (p1.x - p2.x) + ((lld)p1.y - p2.y) * (p1.y - p2.y));
    }
};

struct cmp {
    bool operator()(info A, info B) {
        return A.dist > B.dist;
    }
};

priority_queue<info, vector<info>, cmp> pq;
vector<pos> v;
vector<int> u;
int N, M;


int find(int X) {
    if (X == u[X]) return X;
    else return u[X] = find(u[X]);
}

bool merge(int A, int B) {
    A = find(A);
    B = find(B);
    if (A == B) return false;
    if (A < B) u[B] = A;
    else u[A] = B;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(2);
    cin >> N >> M;
    v.resize(N);
    u.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y;
        u[i] = i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            pq.push({ i, j, v[i], v[j] });
        }
    }
    int cnt = 0;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (merge(--a, --b)) cnt++;
    }
    double result = 0;
    while (!pq.empty() && cnt != N - 1) {
        info now = pq.top();
        pq.pop();
        if (merge(now.a, now.b)) cnt++, result += now.dist;
    }
    cout << result;
    return 0;
}
