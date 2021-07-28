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

vector<vector<int>> v; //0:가로 1:세로
vector<vector<int>> w[2];
queue<vector<int>> q;
int N;


bool isInBound(int ns, int nx, int ny, int dx, int dy) {
    if (ns == 0) {
        if (dy == 1 && ny + 2 < N) return !v[nx][ny + 2];
        if (dy == -1 && ny - 2 >= 0) return !v[nx][ny - 2];
        if (dx == 1 && nx + 1 < N) return !v[nx + 1][ny - 1] && !v[nx + 1][ny] && !v[nx + 1][ny + 1];
        if (dx == -1 && nx - 1 >= 0) return !v[nx - 1][ny - 1] && !v[nx - 1][ny] && !v[nx - 1][ny + 1];
    }
    if (ns == 1) {
        if (dx == 1 && nx + 2 < N) return !v[nx + 2][ny];
        if (dx == -1 && nx - 2 >= 0) return !v[nx - 2][ny];
        if (dy == 1 && ny + 1 < N) return !v[nx - 1][ny + 1] && !v[nx][ny + 1] && !v[nx + 1][ny + 1];
        if (dy == -1 && ny - 1 >= 0) return !v[nx - 1][ny - 1] && !v[nx][ny - 1] && !v[nx + 1][ny - 1];
    }
    return false;
}

bool isAbleTurn(int nx, int ny) {
    if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) return false;
    int FLAG = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            FLAG = FLAG | v[nx + i][ny + j];
        }
    }
    return !FLAG;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> S, E;
    int Ss, Es;
    S = { 0, 0 };
    E = { 0, 0 };
    Ss = Es = -1;

    int i, j, nx, ny, ns, dx, dy;
    string s;
    cin >> N;
    v.resize(N, vector<int>(N, 0));
    w[0].resize(N, vector<int>(N, 0));
    w[1].resize(N, vector<int>(N, 0));

    for (i = 0; i < N; i++) {
        cin >> s;
        for (j = 0; j < N; j++) {
            if (s[j] == '1') v[i][j] = v[i][j] = 1;
            if (s[j] == 'B') {
                S.first += i;
                S.second += j;
                if (S.first / 3 == i - 1) Ss = 1;
                if (S.second / 3 == j - 1) Ss = 0;
            }
            if (s[j] == 'E') {
                E.first += i;
                E.second += j;
                if (E.first / 3 == i - 1) Es = 1;
                if (E.second / 3 == j - 1) Es = 0;
            }
        }
    }
    S = { S.first / 3, S.second / 3 };
    E = { E.first / 3, E.second / 3 };
    q.push({ Ss, S.first, S.second });

    while (!q.empty()) {
        ns = q.front()[0];
        nx = q.front()[1];
        ny = q.front()[2];
        q.pop();
        for (i = 0; i < 4; i++) {
            dx = "2011"[i] - '1';
            dy = "1120"[i] - '1';
            if (isInBound(ns, nx, ny, dx, dy)) {
                if (w[ns][nx + dx][ny + dy] == 0) {
                    w[ns][nx + dx][ny + dy] = w[ns][nx][ny] + 1;
                    q.push({ ns, nx + dx, ny + dy });
                }
            }
        }
        if (w[ns ^ 1][nx][ny] == 0 && isAbleTurn(nx, ny)) {
            w[ns ^ 1][nx][ny] = w[ns][nx][ny] + 1;
            q.push({ ns ^ 1, nx, ny });
        }
    }
    cout << w[Es][E.first][E.second];
    return 0;
}