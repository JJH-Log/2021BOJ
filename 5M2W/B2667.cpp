#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
#define MAX 2e5
using namespace std;
#define ll long long

int check[30][30];
int a[30][30];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;

int bfs(int tx, int ty, int cnt) {
    int tmp = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(tx, ty));
    check[tx][ty] = cnt;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (0 <= x + dx[i] && x + dx[i] < n && 0 <= y + dy[i] && y + dy[i] < n) {
                // 다음 노드가 범위안에 있다.
                if (!check[x + dx[i]][y + dy[i]] && a[x + dx[i]][y + dy[i]]) {
                    // 다음 노드에 방문한 적 없고, 건물이 있다.
                    check[x + dx[i]][y + dy[i]] = cnt;
                    q.push(make_pair(x + dx[i], y + dy[i]));
                    tmp++;
                }
            }
        }
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int i, j;
    string s;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s;
        for (j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] || !a[i][j]) continue;
            cnt++;
            res.push_back(bfs(i, j, cnt));
        }
    }

    sort(res.begin(), res.end());
    cout << cnt << '\n';
    for (i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }
    return 0;
}