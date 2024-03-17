#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> tomato;
queue<pair<int, int>> q;

int mato(int v, int w, int status) {
    if (tomato[v][w] == 0) {
        tomato[v][w] = status + 1;
        q.push(make_pair(v, w));
    }
    return 0;
}

int main()
{
    int i,j,M, N, result;
    int temp_x, temp_y;
    cin >> N >> M;
    tomato.resize(M+2, vector<int>(N+2, 0));

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }
    for (i = 0; i < N + 2; i++) {
        tomato[0][i] = -1;
        tomato[M + 1][i] = -1;
    }
    for (i = 0; i < M + 2; i++) {
        tomato[i][0] = -1;
        tomato[i][N + 1] = -1;
    }
    
    while (!q.empty()) {
        temp_x = q.front().first;
        temp_y = q.front().second;
        result = tomato[temp_x][temp_y];
        q.pop();

        mato(temp_x-1, temp_y, result);
        mato(temp_x+1, temp_y, result);
        mato(temp_x, temp_y-1, result);
        mato(temp_x, temp_y+1, result);
    }

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            if (tomato[i][j] == 0) {
                result = 0;
            }
        }
    }

    cout << result-1;
    return 0;
}
