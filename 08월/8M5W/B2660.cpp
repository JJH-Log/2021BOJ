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

vector<vector<int>> v;
vector<vector<int>> w;
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int x, y;
    cin >> N;
    v.resize(N, vector<int>(N, 100));
    w.resize(N);
    while (true) {
        cin >> x >> y;
        if (x == -1) break;
        x--, y--;
        v[x][y] = v[y][x] = 1;
    }
    int i, j, k;
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        }
    }
    int ans;

    for (i = 0; i < N; i++) {
        ans = 0;
        for (j = 0; j < N; j++) if(i!=j) ans = max(ans, v[i][j]);
        w[ans].push_back(i);
    }
    for (i = 0; i < N; i++) {
        if (w[i].size()) {
            cout << i << ' ' << w[i].size() << '\n';
            sort(w[i].begin(), w[i].end());
            for (j = 0; j < w[i].size(); j++) cout << w[i][j] + 1 << ' ';
            break;
        }
    }

    return 0;
}