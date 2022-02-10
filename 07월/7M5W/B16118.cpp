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

struct info {
    int a; //animal index
    int now; //now pos
    int t; //now time
};

struct cmp {
    bool operator()(info& A, info& B) {
       return A.t > B.t;
    }
};

vector<int> v[3]; //0:wolf(fast), 1:wolf (slow), 2:fox
priority_queue<info, vector<info>, cmp> pq;
vector<vector<pair<int, int>>> w;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int i, x, y, d;
    cin >> N >> M;
    v[0].resize(N, MAXINT);
    v[1].resize(N, MAXINT);
    v[2].resize(N, MAXINT);
    w.resize(N);

    for (i = 0; i < M; i++) {
        cin >> x >> y >> d;
        x--, y--;
        d *= 2;
        w[x].push_back({ y, d });
        w[y].push_back({ x, d });
    }
    v[0][0] = 0; pq.push({ 0, 0, 0 });
    v[2][0] = 0; pq.push({ 2, 0, 0 });
    int now, a, t;

    while (!pq.empty()) {
        a = pq.top().a;
        now = pq.top().now;
        t = pq.top().t;
        pq.pop();
        if (v[a][now] == t) {
            for (auto& next : w[now]) {
                if (a == 2) {
                    if (v[a][next.first] > v[a][now] + next.second) {
                        v[a][next.first] = v[a][now] + next.second;
                        pq.push({ a, next.first, v[a][next.first] });
                    }
                }
                else if (a == 1) {
                    if (v[a ^ 1][next.first] > v[a][now] + next.second * 2) {
                        v[a ^ 1][next.first] = v[a][now] + next.second * 2;
                        pq.push({ a ^ 1, next.first, v[a ^ 1][next.first] });
                    }
                }
                else {
                    if (v[a ^ 1][next.first] > v[a][now] + next.second / 2) {
                        v[a ^ 1][next.first] = v[a][now] + next.second / 2;
                        pq.push({ a ^ 1, next.first, v[a ^ 1][next.first] });
                    }
                }
            }
        }
    }
    int result = 0;
    for (i = 0; i < N; i++) if (min(v[0][i], v[1][i]) > v[2][i]) result++;
    cout << result;
    return 0;
}