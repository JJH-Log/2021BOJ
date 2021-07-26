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

vector<vector<int>> v;
vector<vector<int>> w; // for topological sort
vector<bool> visited;
vector<int> dd; //for depth

bool dfs(int X) {
    int i, next;
    dd[X] = 1;
    for (i = 0; i < w[X].size(); i++) {
        next = w[X][i];
        if (visited[next]) return true;
        else if (!dd[next]) {
            visited[next] = true;
            if (dfs(next)) return true;
            visited[next] = false;
        }
        dd[X] = max(dd[X], dd[next] + 1);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, i, j, k;
    int now, next;
    string s;

    cin >> N >> M;
    v.resize(N, vector<int>(M, 0));
    w.resize(N * M);
    dd.resize(N * M, 0);
    visited.resize(N * M, 0);
    for (i = 0; i < N; i++) {
        cin >> s;
        for (j = 0; j < M; j++) v[i][j] = s[j] - '0';
    }
    int dx, dy;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            now = i * M + j;
            for (k = 0; k < 4; k++) {
                dx = i + v[i][j] * ("2011"[k] - '1');
                dy = j + v[i][j] * ("1120"[k] - '1');
                if (dx >= 0 && dx < N && dy >= 0 && dy < M && v[dx][dy] != 24) {
                    next = dx * M + dy;
                    w[now].push_back(next);
                }
            }
        }
    }
    visited[0] = true;
    if (dfs(0)) cout << -1;
    else cout << dd[0];

    return 0;
}