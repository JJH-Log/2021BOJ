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
    int k; //for key state
    int x;
    int y;
    int d; //for cost
};

struct cmp {
    bool operator()(pos& A, pos& B) {
        return A.d > B.d;
    }
};

priority_queue<pos, vector<pos>, cmp> pq;
vector<vector<int>> v;
vector<vector<vector<int>>> w;
int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    string s;
    pair<int, int> S;
    vector<pair<int,int>> E;
    cin >> N >> M;
    v.resize(N, vector<int>(M, 0));
    w.resize(64, vector<vector<int>>(N, vector<int>(M, 1e9)));
    for (i = 0; i < N; i++) {
        cin >> s;
        for (j = 0; j < M; j++) {
            if (s[j] == '0') S = { i, j };
            if (s[j] == '1') E.push_back({ i, j });
            if (s[j] == '#') v[i][j] = -1;
            if (s[j] >= 'a' && s[j] <= 'f') v[i][j] = s[j] - 'a' + 1;
            if (s[j] >= 'A' && s[j] <= 'F') v[i][j] = s[j] - 'A' + 7;
        }
    }
    w[0][S.first][S.second] = 0;
    pq.push({ 0, S.first, S.second, 0 });

    int k, x, y, d, dx, dy, temp;
    while (!pq.empty()) {
        k = pq.top().k;
        x = pq.top().x;
        y = pq.top().y;
        d = pq.top().d;
        //cout << "now : " << k << ' ' << x << ' ' << y << ' ' << d << endl;
        pq.pop();
        if (w[k][x][y] == d) {
            for (i = 0; i < 4; i++) {
                dx = x + "2011"[i] - '1';
                dy = y + "1120"[i] - '1';
                if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
                    if (v[dx][dy] == 0 && w[k][dx][dy] > w[k][x][y] + 1) {
                        w[k][dx][dy] = w[k][x][y] + 1;
                        pq.push({ k, dx, dy, w[k][dx][dy] });
                    }
                    if (v[dx][dy] >= 1 && v[dx][dy] < 7) {
                        temp = 1 << (v[dx][dy] - 1);
                        if (w[k | temp][dx][dy] > w[k][x][y] + 1) {
                            w[k | temp][dx][dy] = w[k][x][y] + 1;
                            pq.push({ k | temp, dx, dy, w[k | temp][dx][dy] });

                        }
                    }
                    else if (v[dx][dy] >= 7) {
                        temp = 1 << (v[dx][dy] - 7);
                        if ((k & temp) && w[k][dx][dy] > w[k][x][y] + 1) {
                            w[k][dx][dy] = w[k][x][y] + 1;
                            pq.push({ k, dx, dy, w[k][dx][dy] });
                        }
                    }
                }
            }
        }
    }
    int result = 1e9;
    for (auto& now : E) for (i = 0; i < 64; i++) result = min(result, w[i][now.first][now.second]);
    if (result == 1e9) cout << -1;
    else cout << result;

    return 0;
}