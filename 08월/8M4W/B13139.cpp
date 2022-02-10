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
#define MOD 10007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int gcd(int X, int Y) {
    if (Y == 0) return X;
    return gcd(Y, X % Y);
}

bool isPrime(int X) {
    if (X == 2) return true;
    if (X % 2 == 0) return false;
    int qX = sqrt(X);
    for (int i = 3; i <= qX; i += 2) {
        if (X % i == 0) return false;
    }
    return true;
}

int getPrimeX(int x, int d) {
    while(true) {
        if (isPrime(x)) return x;
        x += d;
    }
}

int getPrimeY(int y, int d, int x1, int x2) {
    while (true) {
        if (y == 1) return y;
        if (isPrime(y)) {
            bool FLAG = true;
            for (int i = x1; i <= x2; i++) {
                if (i % y == 0) FLAG = false;
            }
            if (FLAG) return y;
        }
        y += d;
    }
}


vector<vector<int>> v;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, nx, ny, dx, dy;
    lld result;
    int p1, p2, q1, q2;
    cin >> x >> y;
    if (x < y) swap(x, y);
    if (y == 1 || y == 0) {
        cout << x + y;
        return 0;
    }
    p1 = getPrimeX(x, -1);
    p2 = getPrimeX(x, 1);
    q1 = getPrimeY(y, -1, p1, p2);
    q2 = getPrimeY(y, 1, p1, p2);

    //cout << "p1, p2, q1, q2 : " << p1 << ' ' << p2 << ' ' << q1 << ' ' << q2 << endl;

    v.resize(p2 - p1 + 1, vector<int>(q2 - q1 + 1, 0));
    v[x - p1][y - q1] = 1;
    q.push({ x, y });
    while (!q.empty()) {
        nx = q.front().first;
        ny = q.front().second;
        q.pop();
        if (nx == p1 && ny == q1) {
            cout << v[0][0] - 1 + p1 + q1;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            dx = nx + "2011"[i] - '1';
            dy = ny + "1120"[i] - '1';
            if (dx >= p1 && dx <= p2 && dy >= q1 && dy <= q2 && !v[dx - p1][dy - q1]) {
                if (gcd(dx, dy) == 1) {
                    v[dx - p1][dy - q1] = v[nx - p1][ny - q1] + 1;
                    q.push({ dx , dy });
                }
                else v[dx - p1][dy - q1] = -1;
            }
        }
    }
    cout << -1;
    return 0;
}