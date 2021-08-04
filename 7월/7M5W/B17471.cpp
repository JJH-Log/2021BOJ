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


vector<int> v;
vector<vector<int>> w;
vector<bool> vtd;
int N, T;

int dfs(int now, int state) {
    int result = v[now];
    for (auto& next : w[now]) {
        if (!vtd[next] && ((1 << next) & state)) {
            vtd[next] = true;
            result += dfs(next, state);
        }
    }
    return result;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v.resize(N, 0);
    w.resize(N);

    int i, j, temp, M, G, A, B;
    T = 0;
    for (i = 0; i < N; i++) cin >> v[i], T += v[i];
    for (i = 0; i < N; i++) {
        cin >> M;
        for (j = 0; j < M; j++) {
            cin >> temp;
            w[temp - 1].push_back(i);
            w[i].push_back(temp - 1);
        }
    }
    int result = 1e9;
    for (i = 0; i < (1 << N); i++) {
        A = B = -1;
        vtd.clear();
        vtd.resize((1 << N), false);
        for (j = 0; j < N; j++) {
            if (!vtd[j] && ((1 << j) & i) == (1 << j)) vtd[j] = true, A = dfs(j, i), j = N;
        }
        vtd.clear();
        vtd.resize((1 << N), false);
        for (j = 0; j < N; j++) {
            if (!vtd[j] && ((1 << j) & i) != (1 << j)) vtd[j] = true, B = dfs(j, (1 << N) - i - 1), j = N;
        }
        if (A + B == T) result = min(result, abs(A - B));
    }
    if (result == 1e9) cout << -1;
    else cout << result;
    return 0;
}