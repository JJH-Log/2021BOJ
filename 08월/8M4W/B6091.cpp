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

struct connection {
    int x, y, d;
};

struct cmp {
    bool operator()(connection& A, connection& B) { return A.d > B.d; }
};

priority_queue<connection, vector<connection>, cmp> pq;
vector<vector<int>> w;
vector<int> u;
int N, cnt;

void init() {
    w.resize(N);
    u.resize(N, 0);
    cnt = 0;
    for (int i = 0; i < N; i++) u[i] = i;
}

int find(int X) {
    if (u[X] == X) return X;
    return u[X] = find(u[X]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, temp;
    cin >> N;
    init();
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            cin >> temp;
            pq.push({ i, j, temp });
        }
    }
    connection now;
    int a, b;
    while (cnt != N - 1) {
        now = pq.top();
        pq.pop();
        a = find(now.x);
        b = find(now.y);
        if (a == b) continue;
        if (a > b) swap(a, b);
        u[b] = a;
        w[now.x].push_back(now.y);
        w[now.y].push_back(now.x);
        cnt++;
    }
    for (i = 0; i < N; i++) {
        sort(w[i].begin(), w[i].end());
        cout << w[i].size() << ' ';
        for (j = 0; j < w[i].size(); j++) cout << w[i][j] + 1<< ' ';
        cout << '\n';
    }
    return 0;
}