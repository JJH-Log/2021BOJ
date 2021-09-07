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

struct toilet {
    int D, H, idx, k;
};

struct cmp {
    bool operator()(toilet& A, toilet& B) {
        if (A.D == B.D) {
            if (A.H == B.H) return A.idx > B.idx;
            return A.H < B.H;
        }
        return A.D < B.D;
    }
};

vector<pair<int, int>> v;
priority_queue<toilet, vector<toilet>, cmp> pq;
int N, M, K;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    for (int i = 0; i < min(N, M); i++) pq.push({ v[i].first, v[i].second, i, i });
    int result = 0;
    toilet now;
    while (!pq.empty()) {
        now = pq.top();
        pq.pop();
        if (now.k == K) break;
        if (now.k + M < N) pq.push({ v[now.k + M].first, v[now.k + M].second, now.idx, now.k + M });
        result++;
    }
    cout << result;
    return 0;
}