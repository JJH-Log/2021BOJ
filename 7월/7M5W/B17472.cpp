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
    int d;
    int x;
    int y;
};

struct cmp {
    bool operator()(info& A, info& B) {
        return A.d > B.d;
    }
};

priority_queue<info, vector<info>, cmp> pq;
vector<vector<int>> v;
vector<vector<int>> w;
vector<int> f;
int N, M, dfsn;

int find(int X) {
    if (f[X] == X) return X;
    else return f[X] = find(f[X]);
}

bool isIn(int x, int y) {
    return (x >= 0) && (x < N) && (y >= 0) && (y < M);
}

void doLabel(int x, int y, int num) {
    v[x][y] = num;
    for (int i = 0; i < 4; i++) {
        int dx = x + "2011"[i] - '1';
        int dy = y + "1120"[i] - '1';
        if (isIn(dx, dy) && !v[dx][dy]) doLabel(dx, dy, num);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    cin >> N >> M;
    v.resize(N, vector<int>(M, 0));
    dfsn = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) cin >> v[i][j], v[i][j]--;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (v[i][j] == 0)  doLabel(i, j, ++dfsn);
        }
    }
    
    w.resize(dfsn, vector<int>(dfsn, MAXINT));
    int before, dist;

    for (i = 0; i < N; i++) {
        before = -1, dist = 0;
        for (j = 0; j < M; j++) {
            if (v[i][j] == -1) dist++;
            else if (before != v[i][j]) {
                if (before != -1 && dist > 1) w[before - 1][v[i][j] - 1] = min(w[before - 1][v[i][j] - 1], dist);
                before = v[i][j];
                dist = 0;
            }
            else if (before == v[i][j]) dist = 0;
        }
    }
    for (j = 0; j < M; j++) {
        before = -1, dist = 0;
        for (i = 0; i < N; i++) {
            if (v[i][j] == -1) dist++;
            else if (before != v[i][j]) {
                if (before != -1 && dist > 1) w[before - 1][v[i][j] - 1] = min(w[before - 1][v[i][j] - 1], dist);
                before = v[i][j];
                dist = 0;
            }
            else if (before == v[i][j]) dist = 0;
        }
    }
    
    for (i = 0; i < dfsn; i++) {
        for (j = 0; j < dfsn; j++) {
            if (i != j && w[i][j] != MAXINT) pq.push({ w[i][j], i, j });
        }
    }

    f.resize(dfsn, 0);
    for (i = 0; i < dfsn; i++) f[i] = i;

    int d, x, y, result;
    result = 0;
    while (!pq.empty()) {
        d = pq.top().d;
        x = pq.top().x;
        y = pq.top().y;
        pq.pop();
        x = find(x);
        y = find(y);
        if (x == y) continue;
        else {
            if (x > y) f[x] = y;
            else f[y] = x;
            result += d;
        }
    }

    for (i = 0; i < dfsn; i++) find(i);
    for (i = 0; i < dfsn; i++) if (f[i] != 0) {
        cout << -1;
        return 0;
    }
    cout << result << '\n';

    return 0;
}