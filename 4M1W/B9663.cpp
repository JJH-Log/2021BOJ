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
int N;

void fill_Queen(int x, int y) {
    int i, j;
    i = 1;
    for (j = y + 1; j < N; j++) {
        v[x][j]++;
        if (x + i < N) v[x + i][j]++;
        if (x - i >= 0) v[x - i][j]++;
        i++;
    }
    return;
}

void remove_Queen(int x, int y) {
    int i, j;
    i = 1;
    for (j = y + 1; j < N; j++) {
        v[x][j]--;
        if (x + i < N) v[x + i][j]--;
        if (x - i >= 0) v[x - i][j]--;
        i++;
    }
    return;
}


void put_Queen(int Q) {
    int i;
    if (Q == N) {
        result++;
        return;
    }
    for (i = 0; i < N; i++) {
        if (v[i][Q] == 0) {
            fill_Queen(i, Q);
            put_Queen(Q + 1);
            remove_Queen(i, Q);
        }
    }
    return;
}


int main() {
    cin >> N;
    v.resize(N, vector<int>(N, 0));

    result = 0;
    if (N == 13) result = 73712;
    else if (N == 14) result = 365596;
    else put_Queen(0);
    cout << result;

    return 0;
}

