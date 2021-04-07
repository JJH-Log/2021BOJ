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
int result;
vector<pair<int,int>> moves;


int main() {
    int i, j, N, M;
    
    int rx, ry, rd;
    moves.push_back(make_pair(-1, 0)); //N 0
    moves.push_back(make_pair(0, 1)); //E 1
    moves.push_back(make_pair(1, 0)); //S 2
    moves.push_back(make_pair(0, -1)); //W 3

    cin >> N >> M;
    v.resize((N + 2), vector<int>((M + 2), 1));
    cin >> rx >> ry >> rd;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) scanf("%d",&v[i][j]);
    }
    rx += 1; //으으아아ㅏ아ㅏ 시작점 = (0,0)...
    ry += 1;
    while (true) {
        v[rx][ry] = 2;
        if ((v[rx + 1][ry] >= 1) && (v[rx - 1][ry] >= 1) && (v[rx][ry + 1] >= 1) && (v[rx][ry - 1] >= 1)) {
            if (v[rx - moves[rd].first][ry - moves[rd].second] == 1) break;
            else {
                rx -= moves[rd].first;
                ry -= moves[rd].second;
            }
        }
        else {
            rd = (rd + 3) % 4;
            while (v[rx + moves[rd].first][ry + moves[rd].second] >= 1) { rd = (rd + 3) % 4; }
            rx += moves[rd].first;
            ry += moves[rd].second;
        }
    }
    int result = 0;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            if (v[i][j] == 2) result++;
        }
    }

    cout << result;
    return 0;
}

