#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용

//오버플로우 고려해주기.........

using namespace std;

vector<vector<int>> v;
vector<int> ar1;
vector<int> ar2;

int find_target(int X) {
    int left, right, mid, move, count;
    left = 0;
    right = ar2.size() - 1;

    while (left <= right) {
        mid = (left + right + 1) / 2;
        if (ar2[mid] < X) left = mid + 1;
        if (ar2[mid] > X) right = mid - 1;
        if (ar2[mid] == X) {
            count = 1;
            move = 1;
            while (ar2[mid + move] == X) { move++; count++; }
            move = -1;
            while (ar2[mid + move] == X) { move--; count++; }
            return count;
        }
    }
    return 0;
}

int main() {
    int i, j, N;

    scanf("%d", &N);
    v.resize(4, vector<int>(N, 0));
    ar1.resize(N * N, 0);
    ar2.resize(N * N, 0);

    for (i = 0; i < N; i++) scanf("%d %d %d %d", &v[0][i], &v[1][i], &v[2][i], &v[3][i]);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            ar1[i * N + j] = v[0][i] + v[1][j];
            ar2[i * N + j] = v[2][i] + v[3][j];
        }
    }
    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());

    long long result = 0;
    int X = 0;
    int Y = N * N - 1;

    while (true) {
        if ((X == N * N) || (Y == -1)) break;
        if (ar1[X] + ar2[Y] < 0) X++;
        else if (ar1[X] + ar2[Y] > 0) Y--;
        else {
            int tempX = X;
            int tempY = Y;
            while (ar1[tempX] == ar1[X]) {
                tempX++;
                if (tempX == N * N) break;
            }
            while (ar2[tempY] == ar2[Y]) {
                tempY--;
                if (tempY == -1) break;
            }
            result += (long long)(tempX - X) * (Y - tempY);
            X = tempX;
            Y = tempY;
        }
    }
    //for (i = 0; i < N * N; i++) {
    //    result += find_target((-1) * ar1[i]);
    //}

    cout << result;
    return 0;
}
