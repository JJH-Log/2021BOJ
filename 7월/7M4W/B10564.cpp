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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<bool>> v; //point, total
vector<int> w;

void _clear() {
    vector<vector<bool>> x;
    vector<int> y;
    v.swap(x);
    w.swap(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k, t, T, N, M, result;
    int point, total;
    cin >> T;
    for (t = 0; t < T; t++) {
        cin >> N >> M;
        result = -1;
        v.resize(700, vector<bool>(N + 1, false));
        w.resize(M, 0);
        for (i = 0; i < M; i++) {
            cin >> w[i];
            v[w[i]][w[i]] = true;
        }
        for (i = 0; i < 700; i++) {
            for (j = 0; j <= N; j++) {
                if (v[i][j]) {
                    for (k = 0; k < M; k++) {
                        if (j + i + w[k] <= N) v[i + w[k]][j + i + w[k]] = true;
                    }
                }
            }
        }

        for (i = 0; i < 700; i++) if (v[i][N]) result = max(result, i);


        cout << result << '\n';
        v.clear();
        w.clear();
    }
    return 0;
}