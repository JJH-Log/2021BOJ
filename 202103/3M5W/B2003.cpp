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

vector<int> v;

int main() {
    int i, N, M;
    cin >> N >> M;
    v.resize((N + 1), 0);
    for (i = 0; i < N; i++) scanf("%d", &v[i]);

    int result = 0, temp = 0, X = 0, Y = 0;
    while (true) {
        if (temp < M) {
            if (Y >= N) break;
            temp += v[Y];
            Y++;
        }
        else if (temp > M) {
            temp -= v[X];
            X++;
        }
        if (temp == M) {
            result++;
            temp = temp + v[Y] -v[X];
            Y++;
            X++;
        }
    }
    cout << result;
}

