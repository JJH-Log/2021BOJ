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
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v, w;
int N, M, A, B, C, T;

vector<vector<int>> conv(vector<vector<int>> A, vector<vector<int>> B) { //size should be correct (m x n) * (n x o)
    vector<vector<int>> result;
    int m, n, o;
    m = A.size(), n = B.size(), o = B[0].size();
    result.resize(m, vector<int>(o, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < o; j++) {
            for (int k = 0; k < n; k++) result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % M;
        }
    }
    return result;
}

vector<vector<int>> getSqaure(vector<vector<int>> A, int T) {
    vector<vector<int>> result;
    result.resize(A.size(), vector<int>(A.size(), 0));
    for (int i = 0; i < N; i++) result[i][i] = 1;
    while (T) {
        if (T % 2) result = conv(result, A);
        T /= 2;
        A = conv(A, A);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (true) {
        cin >> N >> M >> A >> B >> C >> T;
        if (!N) break;
        v.resize(N, vector<int>(1, 0));
        w.resize(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) cin >> v[i][0];
        for (int i = 0; i < N; i++) {
            if (i > 0) w[i][i - 1] = A;
            w[i][i] = B;
            if (i < N - 1) w[i][i + 1] = C;
        }
        w = getSqaure(w, T);
        v = conv(w, v);
        for (int i = 0; i < N; i++) cout << v[i][0] << ' ';
        cout << '\n';
        v.clear();
        w.clear();
    }

    return 0;
}