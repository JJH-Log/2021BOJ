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
    int x, y;
    double d;
};

struct cmp {
    bool operator()(pos& A, pos& B) {
        return A.d > B.d;
    }
};

map<pair<int, int>, double> m;
priority_queue<pos, vector<pos>, cmp> pq;
int N, F;
double r2, r3;

double dist(int dx, int dy) {
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, x, y;
    double d;
    cin >> N >> F;
    
    r2 = sqrt(2);
    r3 = sqrt(3);

    for (i = 0; i < N; i++) {
        cin >> x >> y;
        m[{x, y}] = 1e9;
    }
    m[{0, 0}] = 0;
    pq.push({ 0,0,0 });

    while (!pq.empty()) {
        x = pq.top().x;
        y = pq.top().y;
        d = pq.top().d;
        pq.pop();
        if (y >= F) {
            cout << (int)(d + 0.5);
            return 0;
        }
        if (m[{x, y}] == d) {
            
            for (i = -2; i <= 2; i++) {
                for (j = -2; j <= 2; j++) {
                    if (m.count({ x + i, y + j }) && m[{x + i, y + j}] > d + dist(i, j)) {
                        m[{x + i, y + j}] = d + dist(i, j);
                        pq.push({ x + i, y + j, d + dist(i, j) });
                    }
                }
            }

        }
    }
    cout << -1;
    
    return 0;
}