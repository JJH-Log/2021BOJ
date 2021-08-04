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
    int x, y, r; //r for rank (w[i][j])
};

struct cmp {
    bool operator()(pos& A, pos& B) {
        return A.r > B.r;
    }
};

vector<vector<int>> v;
vector<vector<int>> ans;
vector<vector<bool>> vtd;
queue<pair<int, int>> q;

priority_queue<pos, vector<pos>, cmp> pq;

int N, M, sCnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    pair<int, int> S[2];
    int i, j, n;
    string s;
    n = 0;
    v.resize(N, vector<int>(M, 0));
    ans.resize(N, vector<int>(M, 1e9));
    vtd.resize(N, vector<bool>(M, false));

    for (i = 0; i < N; i++) {
        cin >> s;
        for (j = 0; j < M; j++) {
            if (s[j] == 'X') v[i][j] = -1;
            else {
                if(s[j] == 'L') S[n++] = { i, j };
                q.push({ i, j });
            }
        }
    }

    int x, y, r, dx, dy;  //labeling for ice
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            dx = x + "2011"[i] - '1';
            dy = y + "1120"[i] - '1';
            if (dx >= 0 && dx < N && dy >= 0 && dy < M && v[dx][dy] == -1) {
                v[dx][dy] = v[x][y] + 1;
                q.push({ dx, dy });
            }
        }
    }
    vtd[S[0].first][S[0].second] = true;
    ans[S[0].first][S[0].second] = 1e9;
    pq.push({ S[0].first, S[0].second, 0 });
    while (!pq.empty() && ans[S[1].first][S[1].second] == 1e9) {
        x = pq.top().x;
        y = pq.top().y;
        r = pq.top().r;
        pq.pop();
        for (i = 0; i < 4; i++) {
            dx = x + "2011"[i] - '1';
            dy = y + "1120"[i] - '1';
            if (dx >= 0 && dx < N && dy >= 0 && dy < M && !vtd[dx][dy]) {
                vtd[dx][dy] = true;
                ans[dx][dy] = max(v[dx][dy], r);
                pq.push({ dx, dy, ans[dx][dy] });
            }
        }
    }
    cout << ans[S[1].first][S[1].second];
    return 0;
}