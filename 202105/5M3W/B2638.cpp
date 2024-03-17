#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

vector<vector<int>> v;
queue<pair<int,int>> bfs;
queue<pair<int,int>> cheese;
queue<pair<int, int>> dummy;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, N, M, result, cnt, air;
    int x, y, dx, dy;
    cin >> N >> M;

    v.resize(N, vector<int>(M, 0));
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) cin >> v[i][j], v[i][j]++;
    }
    bfs.push({ 0,0 });
    v[0][0] = 0;
    result = 0;
    cnt = 0;
    while (true) {
        while (!bfs.empty()) {
            x = bfs.front().first;
            y = bfs.front().second;
            bfs.pop();
            for (i = 0; i < 4; i++) {
                dx = x + "2011"[i] - '1';
                dy = y + "1120"[i] - '1';
                if (dx >=0 && dx < N && dy >=0 && dy < M){
                    if (v[dx][dy] == 2) v[dx][dy]++, cheese.push({ dx , dy });
                    if (v[dx][dy] == 1) v[dx][dy] = 0, bfs.push({ dx, dy });
                }
            }
        }

        if (cheese.empty()) break;
        else {
            result++;
            cnt = 0;
            while (!cheese.empty()) {
                x = cheese.front().first;
                y = cheese.front().second;
                cheese.pop();
                v[x][y] = 2;
                air = 0;
                for (i = 0; i < 4; i++) {
                    dx = x + "2011"[i] - '1';
                    dy = y + "1120"[i] - '1';
                    if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
                        if (!v[dx][dy]) air++;
                    }
                }
                if (air > 1) {
                    cnt++;
                    bfs.push({ x,y });
                    dummy.push({ x,y });
                }
            }
            while (!dummy.empty()) {
                v[dummy.front().first][dummy.front().second] = 0;
                dummy.pop();
            }
        }
    }
    cout << result;

    return 0;
}