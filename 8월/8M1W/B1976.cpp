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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    v.resize(N, vector<int>(N, 1e8));
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> v[i][j];
            if (!v[i][j]) v[i][j] = 1e8;
        }
        v[i][i] = 1;
    }

    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) if (v[i][j] > v[i][k] + v[k][j]) v[i][j] = v[i][k] + v[k][j];
        }
    }

    int before, now;
    bool FLAG = true;
    cin >> before;
    before--;
    for (i = 1; i < M; i++) {
        cin >> now;
        now--;
        if (before >= N || now >= N) {
            cout << "NO";
            return 0;
        }
        if (v[before][now] == 1e8) FLAG = false;
        before = now;
    }
    if (FLAG) cout << "YES";
    else cout << "NO";
    return 0;
}